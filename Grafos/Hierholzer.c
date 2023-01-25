#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int id;
    int jaPercorreu;
    struct no** nos_adj;
}no_t;

int** ler_arquivo_pajek(char nome_arquivo[], int n_vertices){
    FILE* arquivo = NULL;
    int** matriz = NULL;
    int v1, v2;
    matriz = (int**)malloc(n_vertices*sizeof(int*));
    for(int i = 0; i < n_vertices; i++)
        matriz[i] = (int*)calloc(n_vertices,sizeof(int));
    arquivo = fopen(nome_arquivo, "r");
    while(!feof(arquivo)){
        fscanf(arquivo, "%d %d", &v1, &v2);
        matriz[v1-1][v2-1] = 1; //-1 porque passa de numero para pos em vetor
        matriz[v2-1][v1-1] = 1;
    }
    fclose(arquivo);
    return matriz;
}

int** criar_matriz_adjacencias(int** matriz, int n_vertices){
    int n_adj;
    int** matriz_adj = (int**)malloc(n_vertices*sizeof(int*));
    for(int i = 0; i < n_vertices; i++)
        matriz_adj[i] = (int*)calloc(n_vertices, sizeof(int));
    for(int i = 0; i < n_vertices; i++){
        printf("[");
        n_adj = 0;
        for(int j = 0; j < n_vertices; j++)
            if(i != j && matriz[i][j] == 1 && n_adj == 0){
                matriz_adj[i][n_adj] = j;
                printf("%d", j+1);  //+1 porque passa de pos em vetor para numero
                n_adj++;     
            } 
            else if(i != j && matriz[i][j] == 1 && n_adj > 0){
                matriz_adj[i][n_adj] = j;
                printf(", %d", j+1);
                n_adj++;
            }
        printf("]\n");
    }
    return matriz_adj;
}

void Hierholzer(int** matriz_adj, int n_vertices){
    int* nos = (int*)malloc(n_vertices*sizeof(int));
    int nos_percorridos = 0;
    for(int i = 0; i < n_vertices; i++)
        nos[i] = 1;
    while(percorreu )
}

int main(){
    char nome_arquivo[30];
    int n_vertices;
    int** matriz = NULL;
    printf("digite o nome do arquivo pajek: ");
    scanf(" %s", nome_arquivo);
    printf("digite o numero de vertices: ");
    scanf("%d", &n_vertices);
    matriz = ler_arquivo_pajek(nome_arquivo, n_vertices);
    printar_adjacencias(matriz, n_vertices);
    for(int i = 0; i < n_vertices; i++)
        free(matriz[i]);
    free(matriz);
    return 0;
}