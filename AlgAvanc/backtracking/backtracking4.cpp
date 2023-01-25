//
// Created by Yann on 28/09/2021.
//

#include "stdio.h"
#include "stdlib.h"
#include <vector>
#include <algorithm>    // std::sort
//#include <chrono>

using namespace std;


struct node_t{
    int wheel;
    int dist_start;
    int dist_end;
    int f_cost;
    int n_clicks;
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

void find_digits(int wheel, int* digits){
    digits[0] = wheel/1000%10;
    digits[1] = wheel/100%10;
    digits[2] = wheel/10%10;
    digits[3] = wheel%10;

}

bool has_wheel_appeared[10][10][10][10] = {false};

vector<int> get_child_nodes(int parent_node){
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
        if(has_wheel_appeared[digits[0]][digits[1]][digits[2]][digits[3]] == false){
            nodes.push_back(current_node);
        }
    }
//    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//    printf("%ld\n", chrono::duration_cast<std::chrono::microseconds>(end - begin).count());
    return nodes;
}

int find_distance(int wheel1, int wheel2){
    int distance = 0;
    int d_w1[4];
    int d_w2[4];
    find_digits(wheel1, d_w1);
    find_digits(wheel2, d_w2);
    for(int i = 0; i < 4; i++)
        distance += abs(d_w1[i] - d_w2[i]);
    return distance;
}

node_t create_node(int wheel, int n_clicks, int start, int target){
    node_t new_node;
    new_node.wheel = wheel;
    new_node.n_clicks = n_clicks;
    new_node.dist_start = find_distance(wheel, start);
    new_node.dist_end = find_distance(wheel, target);
    new_node.f_cost = new_node.dist_start + new_node.dist_end;
    return new_node;
}

bool isForbidden(int node, vector<int> forbidden){
    for(int i = 0; i < (int)forbidden.size(); i++){
        if(node == forbidden[i])
            return true;
    }
    return false;
}


void insert_node(node_t node, vector<node_t>& available_nodes, vector<int> forbidden){
    if(isForbidden(node.wheel, forbidden) == true)
        return;
    for(int i = 0; i < (int)available_nodes.size(); i++){
        if(available_nodes[i].f_cost > node.f_cost){
            available_nodes.insert(available_nodes.begin() + i, node);
            break;
        }
    }
    //if its f_cost is higher than everyone elses
    available_nodes.push_back(node);

}

void expand_node(int start, int target, vector<node_t>& available_nodes, vector<int> forbidden){
    vector<int> new_nodes = get_child_nodes(available_nodes[0].wheel);
    node_t current_node;
    int digits[4];
    for(int i = 0; i < (int)new_nodes.size(); i++){
        find_digits(new_nodes[i], digits);
        has_wheel_appeared[digits[0]][digits[1]][digits[2]][digits[3]] = true;
        current_node = create_node(new_nodes[i], available_nodes[0].n_clicks+1,start, target);
        insert_node(current_node, available_nodes, forbidden);
    }
    available_nodes.erase(available_nodes.begin());
}

void a_alg(int start, int target, vector<int> forbidden){
    vector<node_t> available_nodes;
    bool found_solution = false;
    node_t current_node = create_node(start, 0, start ,target);
    insert_node(current_node, available_nodes, forbidden);
    while(available_nodes.empty() == false){
        if(available_nodes[0].wheel == target){
            printf("%d\n", available_nodes[0].n_clicks);
            found_solution = true;
            break;
        }
        expand_node(start, target, available_nodes, forbidden);
    }
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
        a_alg(start, target, forbidden);

        for(int i = 0; i < n_forbidden; i++)
            free(forbidden_ar[i]);
        free(forbidden_ar);
    }

    return 0;
}