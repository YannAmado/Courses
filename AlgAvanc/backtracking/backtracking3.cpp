//
// Created by Yann on 17/09/2021.
//

#include "stdio.h"
#include "stdlib.h"
#include <vector>
#include <deque>
#include <set>
#include <algorithm>    // std::sort
//#include <chrono>



using namespace std;


int power(int base, int exp){
    int num = 1;
    for(int i = 0; i < exp; i++)
        num = num*base;
    return num;
}

int array_to_int(int num_array[]){
    int num_int = 0;
    for(int i = 0; i < 4; i++)
        num_int += num_array[i]*power(10, 3-i);
    return num_int;
}

bool isForbidden(int node, vector<int> forbidden){
    for(int i = 0; i < (int)forbidden.size(); i++){
        if(node == forbidden[i])
            return true;
    }
    return false;
}

bool no_esta_na_fila(std::vector <int> fila, int no){
    if(find(fila.begin(), fila.end(), no) == fila.end())
        return false;
    return true;
}

void find_digits(int wheel, int* digits){
    digits[0] = wheel/1000%10;
    digits[1] = wheel/100%10;
    digits[2] = wheel/10%10;
    digits[3] = wheel%10;

}

vector<int> get_child_nodes(int parent_node, vector<int> forbidden, bool has_wheel_appeared[10][10][10][10]){
    vector<int> nodes;
    int current_node;
    int wheel;
    int aux;
    int current_decimal;
    int digits[4];
//    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for(int i = 0; i < 8; i++){
        wheel = parent_node;
        current_decimal = power(10, i%4);
        if(i < 4)
            aux = 1;
        else
            aux = -1;
        //if its a 9 on the number and is going to 10, resets to 0
        if(wheel/current_decimal%10 == 9 && aux == 1)
            wheel -= 9*current_decimal;
        //if its a 0 on the number and is going to -1, resets to 9
        else if(wheel/current_decimal%10 == 0 && aux == -1)
            wheel += 9*current_decimal;
        else
            wheel += aux*current_decimal;
        current_node = wheel;
        find_digits(current_node, digits);
        if(has_wheel_appeared[digits[0]][digits[1]][digits[2]][digits[3]] == false and isForbidden(current_node, forbidden) == false){
            nodes.push_back(current_node);
        }
    }
//    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//    printf("%ld\n", chrono::duration_cast<std::chrono::microseconds>(end - begin).count());
    return nodes;
}


void busca_largura(int start, int target, vector<int>forbidden){
    std::set <int> fila_preto;
    std::vector <int> fila_cinza;
    bool has_wheel_appeared[10][10][10][10] = {false};
    int distancia_do_vertice_inicial = 0;
    int vertice_atual;
    std::vector <int> new_nodes;
    bool found_solution = false;

    vertice_atual = start;
    int digits[4];

    fila_cinza.push_back(vertice_atual);
    while(fila_cinza.empty() == false){  //enquanto ainda existirem nos cinzas
        vertice_atual = fila_cinza.front();
        fila_cinza.erase(fila_cinza.begin());  //tira o no da fila cinza e coloca como o vertice atual para analisar os adj

        if(vertice_atual == target){
            printf("%d\n", distancia_do_vertice_inicial);
            found_solution = true;
            break;
        }


        if(vertice_atual != -1){        //o -1 serve para saber se aumenta a distancia
            new_nodes = get_child_nodes(vertice_atual, forbidden, has_wheel_appeared);
            for(int i = 0; i < (int)new_nodes.size(); i++){
                find_digits(new_nodes[i], digits);
                has_wheel_appeared[digits[0]][digits[1]][digits[2]][digits[3]] = true;
                fila_cinza.push_back(new_nodes[i]);
            }
        }


        if(fila_cinza.empty() == false){    //se ainda existem elementos na fila cinza
            if(distancia_do_vertice_inicial == 0 || vertice_atual == -1){  //se for a primeira iteracao, e depois sempre que chegar no 0
                if(fila_cinza.front() != -1 || fila_cinza.back() != -1)   //se o -1 nao for o unico elemento
                    fila_cinza.push_back(-1);
                distancia_do_vertice_inicial++; //aumenta a distancia do vertice inicial
            }
        }

        //a logica do -1 eh
        //Sempre que chega nela, significa que aumentou a distancia
        //Ou seja, ele vai dividir os vertices baseados na distancia
        //Ex: Vertice inicial 1, grafo ao lado                             1 - 2 - 3
        //distancia ate 1 vai ser 0                                       /      /
        //distancia ate 5 e 4 vai ser 1                                  5-4---
    }   //Ai fica : 1 -> 2,5,0 -> 5,0,3 -> 0,3,4 -> 3,4,0

    if(found_solution == false)
        printf("-1\n");
}



int main(){
    int n_tests;
    scanf("%d", &n_tests);

    for(int z = 0; z < n_tests; z++){
        int start_ar[4], target_ar[4];
        scanf("%d %d %d %d", &start_ar[0], &start_ar[1], &start_ar[2], &start_ar[3]);
        scanf("%d %d %d %d", &target_ar[0], &target_ar[1], &target_ar[2], &target_ar[3]);
        int n_forbidden;
        scanf("%d", &n_forbidden);
        int** forbidden_ar = (int**)malloc(n_forbidden*sizeof(int*));
        vector<int> forbidden;
        for(int i = 0; i < n_forbidden; i++){
            forbidden_ar[i] = (int*)malloc(4*sizeof(int));
            scanf("%d %d %d %d", &forbidden_ar[i][0], &forbidden_ar[i][1], &forbidden_ar[i][2], &forbidden_ar[i][3]);
            forbidden.push_back(array_to_int(forbidden_ar[i]));
        }
        int start = array_to_int(start_ar);
        int target = array_to_int(target_ar);
        sort(forbidden.begin(), forbidden.end());
        busca_largura(start, target, forbidden);

        for(int i = 0; i < n_forbidden; i++)
            free(forbidden_ar[i]);
        free(forbidden_ar);
    }

    return 0;
}