//
// Yann Amado Nunes Costa nUSP: 10746943
// Beatriz Aparecida Diniz nUSP: 11925430
// Bruna Azevedo Garcia nUSP: 11381789
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>
#include <arpa/inet.h>
#include "helpers.h"

#ifdef __WIN32__
# include <winsock2.h>
#else
# include <sys/socket.h>
#endif


int main() {

    //criando o socket
    int client_socket;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    char* server_ip;

    //especificando o endereco do server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //escolhendo se a operacao sera na mesma maquina ou em outra
    int op;
    printf("Digite 1 para conexoes em mesma maquina ou 2 pra maquinas diferentes\n");
    scanf("%d", &op);
    if(op == 2){
        printf("Digite o IP do servidor:\n");
        scanf(" %m[^\r\n]", &server_ip);
        //transformando o endereco de string para binario
        inet_pton(AF_INET, server_ip, &(server_address.sin_addr));

    }

    while(connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1);
    printf("Conectado ao servidor\n");


    pthread_t send_thread;
    pthread_create(&send_thread, NULL, send_msg, &client_socket);

    //recebendo os dados
    while(1){
        receive_msg(client_socket);
    }

    //terminando a outra thread
    pthread_join(send_thread, NULL);
    close(client_socket);

    free(server_ip);
    return 0;
}