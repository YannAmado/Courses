//
// Created by Yann on 07/06/2022.
//

#ifndef REDES_HELPERS_H
#define REDES_HELPERS_H

#define BYTES_PER_MSG 4096
#define MAX_MSG_BLOCKS 100

void* send_msg(void* client_socket);

void receive_msg(int client_socket);

#endif //REDES_HELPERS_H




