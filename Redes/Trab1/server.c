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

#include "helpers.h"

#ifdef __WIN32__
# include <winsock2.h>
#else
# include <sys/socket.h>
#endif

#define N_CONNECTIONS 10



int main(){
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);



    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    listen(server_socket, N_CONNECTIONS);

    int client_socket;

    client_socket = accept(server_socket, NULL, NULL);
    if(client_socket == -1)
        printf("Erro ao se conectar\n\n");
    else
        printf("Conectado ao cliente\n");


    pthread_t send_thread;
    pthread_create(&send_thread, NULL, send_msg, &client_socket);

    char client_response[BYTES_PER_MSG];
    while(1){
        receive_msg(client_socket);
    }
    pthread_join(send_thread, NULL);

    close(server_socket);


    return 0;
}