#include <stdio.h>
#include <stdlib.h>
#include <queue>


int** ler_arquivo_pajek(char nome_arquivo[], int* n_vertices){
    FILE* arquivo = NULL;
    int** matriz = NULL;
    char str[30];
    int v1, v2;
    arquivo = fopen(nome_arquivo, "r");
    fscanf(arquivo, " %s %d", str, n_vertices);
    fscanf(arquivo, " %s", str);
    matriz = (int**)malloc(*n_vertices*sizeof(int*));
    for(int i = 0; i < *n_vertices; i++)
        matriz[i] = (int*)calloc(*n_vertices, sizeof(int));

    while(!feof(arquivo)){  //monta a matriz contendo se a aresta entre 2 nos existe ou nao
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
        n_adj = 0;
        for(int j = 0; j < n_vertices; j++)
            if(i != j && matriz[i][j] == 1){
                matriz_adj[i][n_adj] = j+1; //+1 pra transformar de pos em array pra numero
                n_adj++;
            }
    }
    return matriz_adj;
}

bool no_esta_na_fila(std::queue <int> fila, int no){
    int tamanho_fila = fila.size();
    for(int i = 0; i < tamanho_fila; i++){
        if(fila.front() == no)
            return true;
        fila.pop();
    }
    return false;
}

void busca_profundidade(int** matriz_adj, int n_vertices, int vertice_comeco){
    std::queue <int> fila_branco;
    std::queue <int> fila_preto;
    std::queue <int> fila_cinza;
    int* distancia = (int*)malloc(n_vertices*sizeof(int));
    int distancia_do_vertice_inicial = 0;
    int i;
    int vertice_atual = vertice_comeco;
    for(i = 0; i < n_vertices; i++){
        if(vertice_atual != (i+1))    //serve para nao adicionar o vertice de inicio na fila dos brancos
            fila_branco.push(i+1);     //coloca todos nos como brancos, exceto com o que inicia cinza
    }
    fila_cinza.push(vertice_atual);
    while(fila_cinza.empty() == false){  //enquanto ainda existirem nos cinzas
        vertice_atual = fila_cinza.front();
        if(vertice_atual != 0)
            distancia[vertice_atual-1] = distancia_do_vertice_inicial;        //-1 porque eh pos em vetor
        fila_cinza.pop();  //tira o no da fila cinza e coloca como o vertice atual para analisar os adj
        if(vertice_atual != 0){        //o 0 serve para saber se aumenta a distancia
            fila_preto.push(vertice_atual);    //transforma o no em preto
            i = 0;
            while(matriz_adj[vertice_atual-1][i] != 0){   //-1 para transformar em pos, ira rodar ate nao terem mais adjacentes
                if(no_esta_na_fila(fila_preto, matriz_adj[vertice_atual-1][i]) == false)  //verifica se o nao eh preto
                    fila_cinza.push(matriz_adj[vertice_atual-1][i]);
                i++;
            }
        }
        if(fila_cinza.empty() == false){    //se ainda existem elementos na fila cinza
            if(distancia_do_vertice_inicial == 0 || vertice_atual == 0){  //se for a primeira iteracao, e depois sempre que chegar no 0
                if(fila_cinza.front() != 0 || fila_cinza.back() != 0)   //se o 0 nao for o unico elemento
                    fila_cinza.push(0);
                distancia_do_vertice_inicial++; //aumenta a distancia do vertice inicial
            }
        }
        //a logica do 0 eh
        //Sempre que chega nela, significa que aumentou a distancia
        //Ou seja, ele vai dividir os vertices baseados na distancia
        //Ex: Vertice inicial 1, grafo ao lado                             1 - 2 - 3
        //distancia ate 1 vai ser 0                                       /      /
        //distancia ate 5 e 4 vai ser 1                                  5-4---    
    }   //Ai fica : 1 -> 2,5,0 -> 5,0,3 -> 0,3,4 -> 3,4,0
    for(i = 0; i < n_vertices; i++)
        printf("%d ", distancia[i]);
    free (distancia);
}

int main(){
    char nome_arquivo[30];
    int n_vertices;
    int** matriz = NULL;
    int** matriz_adj = NULL;
    scanf(" %s", nome_arquivo);
    matriz = ler_arquivo_pajek(nome_arquivo, &n_vertices);
    matriz_adj = criar_matriz_adjacencias(matriz, n_vertices);
    for(int i = 0; i < n_vertices; i++){
        busca_profundidade(matriz_adj, n_vertices, i + 1); //+1 pra ser vertice e nao pos
        printf("\n");
    }
    for(int i = 0; i < n_vertices; i++){
        free(matriz[i]);
        free(matriz_adj[i]);
    }
    free(matriz);
    free(matriz_adj);
    return 0;
}