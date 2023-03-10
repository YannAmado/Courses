/*
 * Gabriel Santos Souza nUSP: 11208176
 * Yann Amado Nunes Costa nUSP: 10746943
 */

#include "handlers.h"

void create_table_vehicle(char filename_csv[], char filename_bin[]) {
  char buffer[200];
  FILE *bin_file = open_file(filename_bin, "w+");
  FILE *csv_file = open_file(filename_csv, "r");

  // Handle header
  fgets(buffer, 200, csv_file);
  vehicle_header_t header = read_vehicle_header_from_csv(buffer);
  write_vehicle_header(bin_file, header);

  // Handle data
  while (fgets(buffer, 200, csv_file) != NULL) {
    vehicle_t new_vehicle = read_vehicle_from_csv(buffer);
    write_vehicle(bin_file, new_vehicle);
    update_header(header, new_vehicle);
  }

  // Update header
  header.status = '1';
  header.next_reg_byte = ftell(bin_file);
  fseek(bin_file, 0, SEEK_SET);
  write_vehicle_header(bin_file, header);
  fclose(bin_file);
  fclose(csv_file);
}

void create_table_line(char filename_csv[], char filename_bin[]) {
  char buffer[200];
  FILE *bin_file = open_file(filename_bin, "w+");
  FILE *csv_file = open_file(filename_csv, "r");

  // Handle header
  fgets(buffer, 200, csv_file);
  line_header_t header = read_line_header_from_csv(buffer);
  write_line_header(bin_file, header);

  // Handle data
  while (fgets(buffer, 200, csv_file) != NULL) {
    line_t new_line = read_line_from_csv(buffer);
    write_line(bin_file, new_line);
    update_line_header(header, new_line);
  }

  // Update header
  header.status = '1';
  header.next_reg_byte = ftell(bin_file);
  fseek(bin_file, 0, SEEK_SET);
  write_line_header(bin_file, header);

  fclose(bin_file);
  fclose(csv_file);
}

void select_from_vehicles(char filename[]) {
  vehicle_header_t header;
  FILE *bin_file = open_file(filename, "rb");
  header = read_vehicle_header(bin_file);
  if (header.status == '0') { //if file is not consistent
    printf(ERROR_MESSAGE);
    fclose(bin_file);
    return;
  }
  if (header.count == 0) {
    printf(EMPTY_MESSAGE);
    exit(0);
  }
  for (int i = 0; i < header.count + header.count_removed; i++) {
    vehicle_t vehicle = read_vehicle(bin_file, 0);
    if (vehicle.removed != '0') print_vehicle(vehicle);
  }
  fclose(bin_file);
}

void select_from_lines(char filename[]) {
  line_header_t header;
  FILE *bin_file = open_file(filename, "rb");
  header = read_line_header(bin_file);
  if (header.status == '0') {//if file is not consistent
    printf(ERROR_MESSAGE);
    fclose(bin_file);
    return;
  }
  if (header.count == 0) {
    printf(EMPTY_MESSAGE);
    exit(0);
  }
  for (int i = 0; i < header.count + header.count_removed; i++) {
    line_t line = read_line(bin_file, 0);
    if (line.removed != '0') print_line(line);
  }
  fclose(bin_file);
}

void find_from_vehicles(char filename[], char fieldname[], char value[]) {
  vehicle_header_t header;
  FILE *bin_file = open_file(filename, "rb");
  header = read_vehicle_header(bin_file);
  if (header.status == '0') { //if file is not consistent
    printf(ERROR_MESSAGE);
    fclose(bin_file);
    return;
  }
  vehicle_t current_vehicle;
  int found = 0;  //its used to know if it should print a vehicle
  int found_total = 0;
  for (int i = 0; i < (header.count + header.count_removed); i++) {
    current_vehicle = read_vehicle(bin_file, 0);
    if (current_vehicle.removed == '1') {  //if the register was not removed
      switch (fieldname[0]) {
        case 'p': //prefixo
          if (strcmp(current_vehicle.prefix, value) == 0) found = 1;
          break;
        case 'd': //data
          if (strcmp(current_vehicle.date, value) == 0) found = 1;
          break;
        case 'q': //quantidade de lugares
          if (current_vehicle.seats == atoi(value)) found = 1;
          break;
        case 'm': //modelo
          if (strcmp(current_vehicle.model, value) == 0) found = 1;
          break;
        case 'c': //categoria
          if (strcmp(current_vehicle.category, value) == 0) found = 1;
          break;
      }
      if (found == 1) {  //if found a match
        print_vehicle(current_vehicle);
        found_total++;    //updates
        found = 0;
      }
    }
  }
  if (found_total == 0) //if it never found any vehicles that match
    printf(EMPTY_MESSAGE);
  fclose(bin_file);
}

void find_from_lines(char filename[], char fieldname[], char value[]) {
  line_header_t header;
  FILE *bin_file = open_file(filename, "rb");
  header = read_line_header(bin_file);
  if (header.status == '0') { //if file is not consistent
    printf(ERROR_MESSAGE);
    fclose(bin_file);
    return;
  }
  line_t current_line;
  int found = 0;  //its used to know if it should print a vehicle
  int found_total = 0;
  for (int i = 0; i < (header.count + header.count_removed); i++) {
    current_line = read_line(bin_file, 0);
    if (current_line.removed == '1') {  //if the register was not removed
      switch (fieldname[2]) {
        case 'd': //codLinha
          if (current_line.line_code == atoi(value)) found = 1;
          break;
        case 'e': //aceitaCartao
          if (current_line.accept_card == value) found = 1;
          break;
        case 'm': //nomeLinha
          if (strcmp(current_line.name, value) == 0) found = 1;
          break;
        case 'r': //corLinha
          if (strcmp(current_line.color, value) == 0) found = 1;
          break;
      }
      if (found == 1) {  //if found a match
        print_line(current_line);
        found_total++;    //updates
        found = 0;
      }
    }
  }
  if (found_total == 0) //if it never found any vehicles that match
    printf(EMPTY_MESSAGE);
  fclose(bin_file);
}

void insert_on_vehicles(char filename[], int n) {
  ;
  FILE *bin_file = open_file(filename, "rb+");
  vehicle_header_t header = read_vehicle_header(bin_file);
  if (!verify_vehicle_header_status(header)) {
    fclose(bin_file);
    return;
  }

  // mark as inconsistent as we are going to start editing the file
  header.status = '0';
  fseek(bin_file, 0, SEEK_SET);
  write_vehicle_header(bin_file, header);

  vehicle_t current_vehicle;
  fseek(bin_file, header.next_reg_byte, SEEK_SET); //offsets the file to where the new vehicle should be registered
  for (int i = 0; i < n; i++) {
    current_vehicle = create_vehicle();
    write_vehicle(bin_file, current_vehicle);
    header.count += 1;
  }

  // update header whit new values
  header.next_reg_byte = ftell(bin_file);
  header.status = '1';
  fseek(bin_file, 0, SEEK_SET); //offsets to the beginning of the file
  write_vehicle_header(bin_file, header); //updates the header
  fclose(bin_file);
  binarioNaTela(filename);
}

void insert_on_lines(char filename[], int n) {
  line_header_t header;
  FILE *bin_file = open_file(filename, "rb+");
  header = read_line_header(bin_file);
  if (!verify_line_header_status(header)) { // file is incosistent
    fclose(bin_file);
    return;
  }

  // mark as inconsistent as we are going to start editing the file
  header.status = '0';
  fseek(bin_file, 0, SEEK_SET);
  write_line_header(bin_file, header);

  line_t current_line;
  fseek(bin_file, header.next_reg_byte, SEEK_SET); //offsets the file to where the new vehicle should be registered
  for (int i = 0; i < n; i++) {
    current_line = create_line();
    write_line(bin_file, current_line);
    header.count += 1;
  }

  // update header whit new values
  header.next_reg_byte = ftell(bin_file);
  header.status = '1';
  fseek(bin_file, 0, SEEK_SET); //offsets to the beginning of the file
  write_line_header(bin_file, header); //updates the header
  fclose(bin_file);
  binarioNaTela(filename);

}

/*
 * parses input and decide what to do
 */
void parse_input() {
  int option, n;
  char filename_in[30], filename_out[30], fieldname[30], value[30];
  scanf("%d", &option);
  switch (option) {
    case 1:
      scanf("%s %s", filename_in, filename_out);
      create_table_vehicle(filename_in, filename_out);
      binarioNaTela(filename_out);
      break;
    case 2:
      scanf("%s %s", filename_in, filename_out);
      create_table_line(filename_in, filename_out);
      binarioNaTela(filename_out);
      break;
    case 3:
      scanf("%s", filename_in);
      select_from_vehicles(filename_in);
      break;
    case 4:
      scanf("%s", filename_in);
      select_from_lines(filename_in);
      break;
    case 5:
      scanf("%s %s", filename_in, fieldname);
      scan_quote_string(value);
      find_from_vehicles(filename_in, fieldname, value);
      break;
    case 6:
      scanf("%s %s", filename_in, fieldname);
      scan_quote_string(value);
      find_from_lines(filename_in, fieldname, value);
      break;
    case 7:
      scanf("%s %d", filename_in, &n);
      insert_on_vehicles(filename_in, n);
      break;
    case 8:
      scanf("%s %d", filename_in, &n);
      insert_on_lines(filename_in, n);
      return;
    default:
      printf(ERROR_MESSAGE);
      return;
  }
}