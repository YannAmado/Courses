#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <list>


int** ler_arquivo_pajek(char nome_arquivo[], int* n_nos){
    FILE* arquivo = NULL;
    int** matriz = NULL;
    char str[30];
    int v1, v2;
    arquivo = fopen(nome_arquivo, "r");
    fscanf(arquivo, " %s %d", str, n_nos);
    fscanf(arquivo, " %s", str);
    matriz = (int**)malloc(*n_nos*sizeof(int*));
    for(int i = 0; i < *n_nos; i++)
        matriz[i] = (int*)calloc(*n_nos, sizeof(int));

    while(!feof(arquivo)){  //monta a matriz contendo se a aresta entre 2 nos existe ou nao
        fscanf(arquivo, "%d %d", &v1, &v2);
        matriz[v1-1][v2-1] = 1; //-1 porque passa de numero para pos em vetor
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
            if(i != j && matriz[i][j] == 1){
                matriz_adj[i][n_adj] = j+1; //+1 pra transformar de pos em array pra numero
                n_adj++;
            }
    }
    return matriz_adj;
}

bool no_esta_na_lista(std::list <int> lista, int no){
    int tamanho_lista = lista.size();
    for(int i = 0; i < tamanho_lista; i++){
        if(lista.front() == no)
            return true;
        lista.pop_front();
    }
    return false;
}

bool no_esta_na_pilha(std::stack <int> pilha, int no){
    int tamanho_pilha = pilha.size();
    for(int i = 0; i < tamanho_pilha; i++){
        if(pilha.top() == no)
            return true;
        pilha.pop();
    }
    return false;
}

void busca_profundidade_algoritmo(int** matriz_adj, int n_nos, int no_comeco, int* no_pai, std::list <int> *lista_branca,
std::stack <int> *pilha_preto, std::stack <int> *pilha_cinza, bool *tem_ciclo) {
    int no_comeco_pos = no_comeco - 1;    //-1 pra ser pos em array
    (*pilha_cinza).push(no_comeco);    //seta o no inicial como cinza
    (*lista_branca).remove(no_comeco);
    //O for abaixo ira montar a pilha dos elementos cinzas completa recursivamente
    //Primeiro verifica se o no ta na fila preto ou cinza
    int no_atual;
    for (int i = 0; i < n_nos; i++) {
        no_atual = matriz_adj[no_comeco_pos][i];
        if (no_atual != 0) {   //verifica se existe aresta entre os nos
            if(no_pai[no_atual-1] == 0)
                no_pai[no_atual-1] = no_comeco;
            if(no_pai[no_comeco_pos] != no_atual){    //se pela busca em profundidade achar um no que ja esteja na fila cinza, significa que esse ja foi encontrado antes e agora formou um ciclo
                if(no_esta_na_pilha(*pilha_cinza, no_atual))
                    *tem_ciclo = true;
            }
            if (no_esta_na_lista(*lista_branca, no_atual))
                busca_profundidade_algoritmo(matriz_adj, n_nos, no_atual, no_pai, lista_branca, pilha_preto, pilha_cinza, tem_ciclo);
        }
    }
    //Quando acabar a recursao, vai a partir do ultimo elemento da pilha colocando no prto e tirando do cinza
    (*pilha_preto).push(no_comeco);
    (*pilha_cinza).pop();
    if ((*pilha_cinza).empty() == true) { //se nao existirem mais nos para poder iterar
        while((*pilha_preto).empty() == false){ //enquanto a pilha preta ainda tiver elementos
            (*pilha_preto).pop();
        }
    }
}

void busca_profundidade(int n_nos, int** matriz_adj){
    std::list <int> lista_branca;
    std::stack <int> pilha_cinza;
    std::stack <int> pilha_preta;
    bool tem_ciclo = false;
    int* no_pai = (int*)calloc(n_nos, sizeof(int));
    FILE* arquivo = fopen("ciclo.txt", "w");
    for(int j = 0; j < n_nos; j++) //reinicia a pilha branca
        lista_branca.push_back(j+1);    //+1 pra representar realmente o numero do no
    while(lista_branca.empty() == false) {    //enquanto ainda existirem elementos para serem iterados
        no_pai[lista_branca.front()-1] = -1;
        busca_profundidade_algoritmo(matriz_adj, n_nos, lista_branca.front(), no_pai, &lista_branca, &pilha_preta,
                                     &pilha_cinza, &tem_ciclo); //+1 pra ser no e nao pos
    }
    if(tem_ciclo == true)
        printf("S");
    else
        printf("N");
    for(int i = 0; i < n_nos; i++)
        printf("no: %d pai: %d\n", i+1, no_pai[i]);
    free(no_pai);
    if(tem_ciclo == true)
        fputc('S', arquivo);
    else
        fputc('N', arquivo);
    fclose(arquivo);
}
int main(){
    char nome_arquivo[30];
    int n_nos;
    int** matriz = NULL;
    int** matriz_adj = NULL;
    scanf(" %s", nome_arquivo);
    matriz = ler_arquivo_pajek(nome_arquivo, &n_nos);
    matriz_adj = criar_matriz_adjacencias(matriz, n_nos);
    busca_profundidade(n_nos, matriz_adj);
    for(int i = 0; i < n_nos; i++){
        free(matriz[i]);
        free(matriz_adj[i]);
    }
    free(matriz);
    free(matriz_adj);
    return 0;
}