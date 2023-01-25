//
// Created by Yann on 17/09/2021.
//

#include "stdio.h"
#include "stdlib.h"
#include <vector>
#include <set>
#include <algorithm>    // std::sort
//#include <chrono>



using namespace std;

struct node_t{
    int wheel;
    int similarity;
    bool increase_distance;
};


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


int find_similarity(int node_wheel, int target){
    int current_decimal;
    int similarity = 0;
    for(int i = 0; i < 4; i++) {
        current_decimal = power(10, i % 4);
        similarity += abs(node_wheel/current_decimal%10 - target/current_decimal%10);
    }
    return similarity;
}

bool no_esta_na_fila(std::vector <node_t> fila, node_t no){
    for(int i = 0; i < fila.size(); i++){
        if(fila[i].wheel == no.wheel)
            return true;
    }
    return false;
}


void insert_on_similarity(vector<node_t>& node_array, node_t node){
    if((int)node_array.size() == 0){
        node_array.push_back(node);
        return;
    }
    for(int i = 0; i < (int)node_array.size(); i++){
        if(node_array[i].similarity < node.similarity)
            node_array.insert(node_array.begin() + i, node);
    }
}

vector<node_t> get_child_nodes(int parent_node, vector<int> forbidden, vector<node_t> fila_cinza, set<int> fila_preta, int target){
    vector<node_t> nodes;
    node_t current_node;
    int wheel;
    int aux;
    int current_decimal;
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
        current_node.wheel = wheel;
        current_node.similarity = find_similarity(wheel, target);
        current_node.increase_distance = false;
        if(no_esta_na_fila(fila_cinza, current_node) == false and fila_preta.find(current_node.wheel) == fila_preta.end() and isForbidden(current_node.wheel, forbidden) == false)
            nodes.push_back(current_node);
    }
//    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//    printf("%ld\n", chrono::duration_cast<std::chrono::microseconds>(end - begin).count());
    return nodes;
}


void busca_largura(int start, int target, vector<int>forbidden){
    std::set <int> fila_preto;
    std::vector <node_t> fila_cinza;
    int distancia_do_vertice_inicial = 0;
    node_t vertice_atual;
    std::vector <node_t> new_nodes;
    bool found_solution = false;
    node_t aux;
    aux.wheel = -1;
    aux.increase_distance = true;
    vertice_atual.wheel = start;
    vertice_atual.similarity = find_similarity(start, target);
    vertice_atual.increase_distance = false;

    fila_cinza.push_back(vertice_atual);
    while(fila_cinza.empty() == false){  //enquanto ainda existirem nos cinzas
        vertice_atual = fila_cinza.front();
        fila_cinza.erase(fila_cinza.begin());  //tira o no da fila cinza e coloca como o vertice atual para analisar os adj

        if(vertice_atual.wheel == target){
            printf("%d\n", distancia_do_vertice_inicial);
            found_solution = true;
            break;
        }


        if(vertice_atual.increase_distance == false){        //o 0 serve para saber se aumenta a distancia
            fila_preto.insert(vertice_atual.wheel);    //transforma o no em preto
            new_nodes = get_child_nodes(vertice_atual.wheel, forbidden, fila_cinza, fila_preto, target);
            for(int i = 0; i < (int)new_nodes.size(); i++){
                insert_on_similarity(fila_cinza, new_nodes[i]);
            }
        }


        if(fila_cinza.empty() == false){    //se ainda existem elementos na fila cinza
            if(distancia_do_vertice_inicial == 0 || vertice_atual.increase_distance == true){  //se for a primeira iteracao, e depois sempre que chegar no 0
                if(fila_cinza.front().increase_distance != true || fila_cinza.back().increase_distance != true)   //se o 0 nao for o unico elemento
                    fila_cinza.push_back(aux);
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