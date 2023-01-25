//
// Created by Yann on 02/11/2021.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define ARRAY_SIZE 1000

using namespace std;

int TOTAL[ARRAY_SIZE];

int find_best_solution(vector<int> price,vector<int> weight, vector<int> people){
    for(int i = 0; i < (int)price.size(); i++){
        for(int j = people.back(); j > 0 ; j--){
            if(weight[i] <= j)
                TOTAL[j] = max(TOTAL[j], TOTAL[j-weight[i]]+price[i]);
        }
    }
    int sum = 0;
    for(int i = 0; i < (int)people.size(); i++)
        sum += TOTAL[people[i]];
    return sum;
}

int main(){
    int n_tests, n_prod, n_people;
    int aux1, aux2;
    vector<int> people, price, weight;
    cin>>n_tests;
    for(int z = 0; z < n_tests; z++){
        people.clear();
        price.clear();
        weight.clear();
        memset(TOTAL, 0, sizeof(TOTAL));
        cin >> n_prod;
        for(int i = 0; i < n_prod; i++){
            scanf("%d %d", &aux1, &aux2);
            price.push_back(aux1);
            weight.push_back(aux2);
        }
        cin >> n_people;
        for(int i = 0; i < n_people; i++){
            cin >> aux1;
            people.push_back(aux1);
        }
        sort(people.begin(), people.end());
        cout << find_best_solution(price, weight, people) << endl;
    }
    return 0;
}