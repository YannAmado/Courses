//
// Created by Yann on 29/10/2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define ARRAY_SIZE 1000000

using namespace std;

struct usedCoins{
    vector<int> coins;
}usedCoins_t;


//how close the problem can get to that specific solution
int TOTAL[ARRAY_SIZE] = {0};

int sum_vector(vector<int> v){
    int sum = 0;
    for(int i = 0; i < (int)v.size();i++)
        sum += v[i];
    return sum;
}


int find_difference(vector<int> coins){
    int best_result = sum_vector(coins)/2;

    for(int j = 0; j < (int)coins.size(); j++){
        for(int i = best_result; i >= coins.front(); i--){
            if(coins[j] <= i)
                TOTAL[i] = max(TOTAL[i], TOTAL[i-coins[j]] + coins[j]);
        }
    }
    return sum_vector(coins)-2*TOTAL[best_result];
}

/*int find_difference(vector<int> remaining_coins, vector<int> coins_p1, vector<int> coins_p2){
    if(remaining_coins.size() == 0){
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < (int)coins_p1.size(); i++)
            sum1 += coins_p1[i];
        for(int i = 0; i < (int)coins_p2.size(); i++)
            sum2 += coins_p2[i];
        return abs(sum1-sum2);
    }
    int coin = remaining_coins.back();
    remaining_coins.pop_back();
    coins_p1.push_back(coin);
    int diff1 = find_difference(remaining_coins, coins_p1, coins_p2);
    coins_p1.pop_back();
    coins_p2.push_back(coin);
    int diff2 = find_difference(remaining_coins, coins_p1, coins_p2);
    return min(diff1, diff2);
}*/

int main(){
    int n_tests, n_coins, aux;
    vector<int> coins;
    cin >> n_tests;
    for(int z = 0; z < n_tests; z++){
        memset(TOTAL, 0, sizeof(TOTAL));
        cin >> n_coins;
        coins.clear();
        for(int i = 0; i < n_coins; i++){
            cin >> aux;
            coins.push_back(aux);
        }
        sort(coins.begin(), coins.end());
        cout << find_difference(coins) << endl;
    }

    return 0;
}