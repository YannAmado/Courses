//Yann Amado Nunes Costa
//n USP: 10746943

#include <stdio.h>
#include <stdlib.h>

typedef struct usuario{
    int id;
    char nome[50];
    int idade;
} usuario_t;


void desalocarMem(char* nomeArquivo, FILE* arquivo, usuario_t* listaUsuarios, int nUsuarios){
    free(nomeArquivo);
    free(listaUsuarios);
    fclose(arquivo);
}

void readStr(FILE* arquivo, char* str){  //le cada linha e repassa a string
    fread(str, sizeof(char), 50, arquivo);
    return;
}

int readInt(FILE* arquivo, int* isEOF){  //le cada linha e repassa a string
    int bytesLidos;
    int numero;
    bytesLidos = fread(&numero, sizeof(int), 1, arquivo);
    if(bytesLidos == 0){
        *isEOF = 1;
        return 0;
    }
    return numero;
}

usuario_t* armazenarDadosUsuario(int* isEOF, FILE* arquivo, usuario_t* listaUsuarios, int nUsuarios){
    int temp;       //serve para guardar a informacao do primeiro campo, pois pode ser que tenha chegado ao fim do arquivo e nao precise executar o resto do codigo
    temp = readInt(arquivo, isEOF);
    if(*isEOF == 1)
        return listaUsuarios;
    listaUsuarios = realloc(listaUsuarios, sizeof(usuario_t)*nUsuarios);
    listaUsuarios[nUsuarios-1].id = temp; //-1 porque eh posicao em vetor
    readStr(arquivo, listaUsuarios[nUsuarios-1].nome);
    listaUsuarios[nUsuarios-1].idade = readInt(arquivo, isEOF);
    return listaUsuarios;
}

int main(){
    char* nomeArquivo = NULL;
    FILE* arquivo = NULL;
    int isEOF = 0;  //indica se chegou no fim do arquivo
    usuario_t* listaUsuarios = NULL;
    int nUsuarios = 0;
    scanf("%m[^\n\r]", &nomeArquivo);
    arquivo = fopen(nomeArquivo, "rb");
    while(isEOF == 0){  
        nUsuarios++;
        listaUsuarios = armazenarDadosUsuario(&isEOF, arquivo, listaUsuarios, nUsuarios);
    }
    nUsuarios--;    //1 iteracao foi para achar o final do arquivo
    for(int i = 0; i < nUsuarios; i++){
        if(listaUsuarios[i].idade >= 18){
            if(listaUsuarios[i].nome[0] != '\0')
                printf("O usuario %s eh de maior.\n", listaUsuarios[i].nome);
            else
                printf("O usuario de identificacao %d eh de maior.\n", listaUsuarios[i].id);
        }
    }
    desalocarMem(nomeArquivo, arquivo, listaUsuarios, nUsuarios);
    return 0;    
}