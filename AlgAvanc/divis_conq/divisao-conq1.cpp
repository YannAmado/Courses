//
// Created by Yann on 29/09/2021.
//

#include <stdio.h>
#include <stdlib.h>

long long int n_swaps = 0;

void fundir(int* arr, int inicio, int fim){
    int tam_v1, tam_v2; //diz o tamanho total de cada um dos vetores
    int pos_v1, pos_v2; //diz em que posicao cada um dos vetores comeca
    int i, j, k; //sao os contadores das posicoes dos vetores v1, v2, v3 e aux respectivamente
    int* aux = NULL;
    aux = (int*)malloc((fim - inicio + 1)*sizeof(int));
    i = 0;
    j = 0;
    k = 0;
    tam_v1 = (fim - inicio + 1)/2;  //denota o numero total de livros nessa iteracao, +1 pra transformar de pos para numero
    tam_v2 = (fim - inicio + 1)/2;
    if((fim - inicio + 1)%2 == 1)
        tam_v1 = tam_v1 + 1;
    pos_v1 = inicio;
    pos_v2 = pos_v1 + tam_v1;
    while(i < tam_v1 && j < tam_v2){
        if(arr[pos_v2 + j] < arr[pos_v1 + i]){
            aux[k] = arr[pos_v2 + j];
            n_swaps += pos_v2 + j - (k + pos_v1);
            j++;
        }
        else{
            aux[k] = arr[pos_v1 + i];
            i++;
        }
        k++;
    }
    while(i < tam_v1){
        aux[k] = arr[pos_v1 + i];
        i++;
        k++;
    }
    while(j < tam_v2){
        aux[k] = arr[pos_v2 + j];
        j++;
        k++;
    }
    for(i = inicio, k = 0; k < fim - inicio + 1; i++, k++)
        arr[i] = aux[k];
    free(aux);
}

void mergesort(int* arr, int inicio, int fim){
    int meio;
    //fim - inicio + 1 descobre o tamanho do vetor
    if(fim <= inicio){
        fundir(arr, inicio, fim);
        return;
    }
    meio = inicio + (fim - inicio)/2;
    //1 via
    mergesort(arr, inicio, meio);
    //2 via
    mergesort(arr, meio + 1, fim);
    //junta as 2 vias
    fundir(arr, inicio, fim);
}

int main(){
    int n_el;
    int* arr;
    scanf("%d", &n_el);
    while(n_el != 0){
        arr = (int*)malloc(n_el*sizeof(int));
        for(int i = 0; i < n_el; i++)
            scanf("%d", &arr[i]);
        mergesort(arr, 0, n_el-1);
        printf("%lld\n", n_swaps);
        n_swaps = 0;
        free(arr);
        scanf("%d", &n_el);
    }
}