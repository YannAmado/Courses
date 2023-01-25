//Yann Amado Nunes Costa
//n USP: 10746943

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void writeStr(FILE* arquivo){  //le cada linha e repassa a string
    char* str;
    scanf(" %m[^ ]", &str);  //le a str ate a barra de espaco
    fwrite(str, strlen(str) + 1, 1, arquivo);
    free(str);
}

void writeInt(FILE* arquivo){  //le cada linha e repassa a string
    int numero;
    scanf(" %d", &numero);
    fwrite(&numero, sizeof(int), 1, arquivo);
}

void escreverDadosUsuario(FILE* arquivo){
    writeInt(arquivo);
    writeStr(arquivo);
    writeInt(arquivo);
}


void binarioNaTela(char *nomeArquivoBinario) { /* Você não precisa entender o código dessa função. */

	/* Use essa função para comparação no run.codes. Lembre-se de ter fechado (fclose) o arquivo anteriormente.
	*  Ela vai abrir de novo para leitura e depois fechar (você não vai perder pontos por isso se usar ela). */

	unsigned long i, cs;
	unsigned char *mb;
	size_t fl;
	FILE *fs;
	if(nomeArquivoBinario == NULL || !(fs = fopen(nomeArquivoBinario, "rb"))) {
		fprintf(stderr, "ERRO AO ESCREVER O BINARIO NA TELA (função binarioNaTela): não foi possível abrir o arquivo que me passou para leitura. Ele existe e você tá passando o nome certo? Você lembrou de fechar ele com fclose depois de usar?\n");
		return;
	}
	fseek(fs, 0, SEEK_END);
	fl = ftell(fs);
	fseek(fs, 0, SEEK_SET);
	mb = (unsigned char *) malloc(fl);
	fread(mb, 1, fl, fs);

	cs = 0;
	for(i = 0; i < fl; i++) {
		cs += (unsigned long) mb[i];
	}
	printf("%lf\n", (cs / (double) 100));
	free(mb);
	fclose(fs);
}


int main(){
    char* nomeArquivo = NULL;
    FILE* arquivo = NULL;
    int nUsuarios;
    scanf("%m[^\n\r]", &nomeArquivo);
    scanf("%d", &nUsuarios);
    arquivo = fopen(nomeArquivo, "wb");
    for(int i = 0; i < nUsuarios; i++)
        escreverDadosUsuario(arquivo);
    fclose(arquivo);    
    binarioNaTela(nomeArquivo);
    free(nomeArquivo);
    return 0;    
}