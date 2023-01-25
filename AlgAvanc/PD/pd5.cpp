//
// Created by Yann on 10/11/2021.
//

#include <iostream>

#define ARRAY_SIZE 1000

int cards[ARRAY_SIZE];
int n_ops[ARRAY_SIZE] = {0};

using namespace std;

//int order_cards(int n){
//    n_ops[0] = 0;
//    for(int i = 1; i <= n; i++){
//        for(int j = 0; j < i; j++){
//            //if the last card is bigger than any card before
//            if(cards[i] >= cards[j] and n_ops[i] < n_ops[j]+1)
//                n_ops[i] = n_ops[j]+1;
//        }
//    }
//    int max = 0;
//    for(int i = 0; i < n; i++){
//        if( max < n_ops[i])
//            max = n_ops[i];
//    }
//
//
//    return n-max-1;
//}

int order_cards(int n){
    n_ops[0] = 0;
    for(int i = 1; i <= n; i++){
        n_ops[i] = n_ops[i-1];
        for(int j = 0; j < i; j++){
            //if the last card is bigger than any card before
            if(cards[i-1] < cards[j])
                n_ops[i] = max(n_ops[i], n_ops[j]+1);
        }
    }
    return n_ops[n];
}


int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cards[i];
    }
    cout << order_cards(n);
    return 0;
}