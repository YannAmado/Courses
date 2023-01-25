//
// Created by Yann on 09/07/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

struct no_t{
    std::vector <no_t> caminho_nos;
    int dist_ate_no;
    int id;
};


void printar_matriz(int** matriz, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int** ler_arquivo_pajek(char nome_arquivo[], int* n_nos){
    FILE* arquivo = NULL;
    int** matriz = NULL;
    char str[30];
    char type[30];
    int v1, v2, weight;
    arquivo = fopen(nome_arquivo, "r");
    fscanf(arquivo, " %s %d", str, n_nos);
    fscanf(arquivo, " %s", type);
    matriz = (int**)malloc(*n_nos*sizeof(int*));
    for(int i = 0; i < *n_nos; i++)
        matriz[i] = (int*)calloc(*n_nos, sizeof(int));

    while(!feof(arquivo)){  //monta a matriz contendo se a aresta entre 2 nos existe ou nao
        fscanf(arquivo, "%d %d %d", &v1, &v2, &weight);
        matriz[v1-1][v2-1] = weight; //-1 porque passa de numero para pos em vetor

        //Se for um grafo nao direcionado
        if(strcmp(type, "*Edges") == true)
            matriz[v2-1][v1-1] = weight; //coloca o valor na inversa
    }
    fclose(arquivo);
    return matriz;
}

int** criar_matriz_adjacencias(int** matriz, int n_nos){
    int n_adj;
    int** matriz_adj = (int**)malloc(n_nos*sizeof(int*));
    for(int i = 0; i < n_nos; i++)
        matriz_adj[i] = (int*)calloc(n_nos, sizeof(int));
    for(int i = 0; i < n_nos; i++){
        n_adj = 0;
        for(int j = 0; j < n_nos; j++)
            if(i != j && matriz[i][j] > 0){
                matriz_adj[i][n_adj] = j+1; //+1 pra transformar de pos em array pra numero
                n_adj++;
            }
    }
    return matriz_adj;
}

void remover_folha_dup(int comeco, std::vector <no_t> folhas){
    for(size_t i = comeco; i < folhas.size(); i++){
        for(size_t j = i+1; j < folhas.size(); j++){
            if(folhas[i].id == folhas[j].id){
                if(folhas[i].dist_ate_no > folhas[j].dist_ate_no)
                    folhas.erase(folhas.begin() + i);
                else
                    folhas.erase(folhas.begin() + j);
                return remover_folha_dup(i, folhas);
            }
        }
    }
}

bool no_esta_no_vetor(std::vector <no_t> lista, no_t no){
    int tamanho_lista = lista.size();
    for(int i = 0; i < tamanho_lista; i++){
        if(lista[i].id == no.id)
            return true;
    }
    return false;
}

void remover_folha(std::vector <no_t> folhas, no_t no_para_remover){
    for(size_t i = 0; i < folhas.size(); i++){
        if(folhas[i].id == no_para_remover.id){
            folhas.erase(folhas.begin() + i);
            return;
        }
    }
}

int search_by_djistrka(int n_nos, int root_pos, int target_pos, int** matriz_adj){
    std::vector <no_t> folhas;
    std::vector <no_t> caminho;
    int root = root_pos + 1;
    int target = target_pos + 1;
    int distancia = 0;
    no_t no_atual;
    no_t no_raiz;
    no_t no_pai;
    no_raiz.id = root;
    no_raiz.id = root;
    no_raiz.dist_ate_no = 0;
    caminho.push_back(no_raiz);
    while(caminho.back().id != target){
        no_pai = caminho.back();
        int no_pai_pos = no_pai.id;

        //Se o no ainda nao estiver na fila
        for(int i = 0; matriz_adj[no_pai_pos][i] > 0; i++){
            no_atual.id = i+1;
            distancia = no_pai.dist_ate_no;
            if(no_esta_no_vetor(caminho, no_atual) == false){
                no_atual.caminho_nos = caminho;
                //distancia ja percorrida + distancia do pai ate o novo no
                no_atual.dist_ate_no = distancia + matriz_adj[no_pai_pos][i];
                no_atual.id = i+1;
                folhas.push_back(no_atual);
            }
        }

        remover_folha_dup(0, folhas);

        no_t folha_expandir = folhas.front();
        int menor_dist = folha_expandir.dist_ate_no;
        for(size_t i = 0; i < folhas.size(); i++){
            if(folhas[i].dist_ate_no < menor_dist){
                menor_dist = folhas[i].dist_ate_no;
                folha_expandir = folhas[i];
            }
        }
        caminho = folha_expandir.caminho_nos;
        caminho.push_back(folha_expandir);

        remover_folha(folhas, folha_expandir);
    }

    return distancia;
}

void djistrka_alg(int n_nos, int** matriz_dist, int** matriz_adj){
    for(int i = 0; i < n_nos; i++){
        for(int j = 0; j < n_nos; j++){
            if(i != j){
                if(matriz_dist[i][j] == 0)
                    matriz_dist[i][j] = search_by_djistrka(n_nos, i, j, matriz_adj);
            }
        }
    }

}

void ex2(std::vector <int> seila){
    seila.erase(seila.begin() + 1);
}

void ex(){
    std::vector <int> seila;
    for(int i = 0; i < 10; i++)
        seila.push_back(i);
    for(size_t i; i < seila.size(); i++)
        printf("%d ", seila[i]);
    printf("\n");
    ex2(seila);
    for(size_t i; i < seila.size(); i++)
        printf("%d ", seila[i]);
}

int main(){
    char nome_arquivo[30];
    int n_nos;
    int** matriz_dist = NULL;
    int** matriz_adj = NULL;
    scanf(" %s", nome_arquivo);
    ex();
    matriz_dist = ler_arquivo_pajek(nome_arquivo, &n_nos);
    matriz_adj = criar_matriz_adjacencias(matriz_dist, n_nos);
    //printar_matriz(matriz_dist, n_nos);
    //djistrka_alg(n_nos, matriz_dist, matriz_adj);
    //printar_matriz(matriz_dist, n_nos);
    for(int i = 0; i < n_nos; i++){
        free(matriz_dist[i]);
        free(matriz_adj[i]);
    }
    free(matriz_dist);
    free(matriz_adj);
    return 0;
}