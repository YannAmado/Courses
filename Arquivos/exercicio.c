//Yann Amado Nunes Costa
//n USP: 10746943

#include <stdio.h>
#include <stdlib.h>

typedef struct usuario{
    int id;
    char* nome;
    int idade;
} usuario_t;


void desalocarMem(char* nomeArquivo, FILE* arquivo, usuario_t* listaUsuarios, int nUsuarios){
    free(nomeArquivo);
    for( int i = 0; i < nUsuarios; i++){
        if(listaUsuarios[i].nome != NULL)
            free(listaUsuarios[i].nome);
    }
    free(listaUsuarios);
    fclose(arquivo);
}

char* readStr(FILE* arquivo){  //le cada linha e repassa a string
    int tamanho_str = 0;
    char letra[1] = "a";    //"a" so para inicializar a variavel
    char* str = NULL;
    int bytesLidos;
    do{
        tamanho_str++;
        str = (char*)realloc(str, tamanho_str*sizeof(char));
        bytesLidos = fread(letra, sizeof(char), 1, arquivo);
        str[tamanho_str - 1] = letra[0];
    } while (letra[0] != '\n' && letra[0] != '\r' && letra[0] != ',' && bytesLidos != 0);
    if (bytesLidos == 0){
        str[tamanho_str - 1] = EOF; //servira para saber o criterio de parada da leitura do arquivo
        return str;
    }
    if(tamanho_str == 1){   //isso significa que nao tem nada no nome
        free(str);
        return NULL;
    }    
    str[tamanho_str - 1] = '\0';
    return str;
}

int readInt(FILE* arquivo, int* isEOF){  //le cada linha e repassa a string
    char* str = readStr(arquivo);
    int numero = 0;
    if(str[0] == EOF)
        *isEOF = 1;
    else
        numero = atoi(str);
    free(str);
    return numero;
}

usuario_t* armazenarDadosUsuario(int* isEOF, FILE* arquivo, usuario_t* listaUsuarios, int nUsuarios){
    int temp;       //serve para guardar a informacao do primeiro campo, pois pode ser que tenha chegado ao fim do arquivo e nao precise executar o resto do codigo
    temp = readInt(arquivo, isEOF);
    if(*isEOF == 1)
        return listaUsuarios;
    listaUsuarios = realloc(listaUsuarios, sizeof(usuario_t)*nUsuarios);
    listaUsuarios[nUsuarios-1].id = temp; //-1 porque eh posicao em vetor
    listaUsuarios[nUsuarios-1].nome = readStr(arquivo);
    listaUsuarios[nUsuarios-1].idade = readInt(arquivo, isEOF);
    return listaUsuarios;
}

void tirarHeader(FILE* arquivo){    //le o header e passa para a proxima linha
    char letra[1];
    do{
        fread(letra, sizeof(char), 1, arquivo);
    }while(letra[0] != '\n' && letra[0] != '\r');
}

int main(){
    char* nomeArquivo = NULL;
    FILE* arquivo = NULL;
    int isEOF = 0;  //indica se chegou no fim do arquivo
    usuario_t* listaUsuarios = NULL;
    int nUsuarios = 0;
    scanf("%m[^\n\r]", &nomeArquivo);
    arquivo = fopen(nomeArquivo, "r");
    tirarHeader(arquivo);
    while(isEOF == 0){  
        nUsuarios++;
        listaUsuarios = armazenarDadosUsuario(&isEOF, arquivo, listaUsuarios, nUsuarios);
    }
    nUsuarios--;    //1 iteracao foi para achar o final do arquivo
    for(int i = 0; i < nUsuarios; i++){
        if(listaUsuarios[i].idade >= 18){
            if(listaUsuarios[i].nome != NULL)
                printf("O usuario %s eh de maior.\n", listaUsuarios[i].nome);
            else
                printf("O usuario de identificacao %d eh de maior.\n", listaUsuarios[i].id);
        }
    }
    desalocarMem(nomeArquivo, arquivo, listaUsuarios, nUsuarios);
    return 0;    
}