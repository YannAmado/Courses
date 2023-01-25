//
// Created by Yann on 07/06/2022.
//

#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef __WIN32__
# include <winsock2.h>
#else
# include <sys/socket.h>
#endif

char* create_block(char* msg, int current_block){
    //+1 pra incluir o '\0'
    char* msg_block = (char*)malloc(sizeof(char)*(BYTES_PER_MSG+1));
    int i = 1;
    int pos = current_block*BYTES_PER_MSG;
    msg_block[0] = msg[pos];
    while(msg[pos + i] != '\n' && msg[pos + i] != '\r' && msg[pos + i] != '\0' && i%BYTES_PER_MSG != 0){
        msg_block[i] = msg[pos + i];
        i++;
    }
    msg_block[i] = '\0';
    return msg_block;
}

void* send_msg(void* client_socket){
    int* client_socket_ptr = (int *) client_socket;
    char* server_message = NULL;
    char* block = NULL;
    while(1){
        server_message = NULL;
        block = NULL;
        scanf(" %m[^\n\r]", &server_message);

        int message_size = 0;
        int n_blocks = 0;

        while(server_message[message_size] != '\0') {
            if(message_size%BYTES_PER_MSG == 0){
                n_blocks++;
            }
            message_size++;
        }
        //enviando os blocos
        int j = 0;
        //send(*client_socket_ptr, server_message, message_size, 0);
        for(int i = 0; i < n_blocks; i++){
            block = create_block(server_message, i);
            //printf("bloco: %s", block);
            while(block[j] != '\0') j++;
            send(*client_socket_ptr, block, j, 0);
            //send(*client_socket_ptr, "\n", sizeof(char), 0);
            free(block);
        }
        free(server_message);
    }

}

void receive_msg(int client_socket){
    char server_response[BYTES_PER_MSG];
    recv(client_socket, &server_response, sizeof(server_response), 0);
    printf("%s\n", server_response);

    //limpa o buffer para que nao imprima lixo;
    for(int i = 0; i < BYTES_PER_MSG; i++)
        server_response[i] = '\0';

}