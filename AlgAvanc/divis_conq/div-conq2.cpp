//
// Created by Yann on 05/10/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int biggest_prod = 0;

void find_solution(set< pair<int,int>> s, int n, int begin, int end){
    if(begin >= n || end < 0 || begin > end){
        return;
    }
    auto it = s.begin();
    int smallest_index = (*it).second;
    int smallest_num = (*it).first;
    if(biggest_prod < smallest_num*(end-begin+1))
        biggest_prod = smallest_num*(end-begin+1);
    //find the next candidate for biggest product
    //the next candidate cannot be a smaller array with the same smallest num
    //so it will go to where the next pos to the smallest num
    set<pair<int, int>> s1;
    find_solution(s, n, smallest_index+1, end);
    find_solution(s1, n, begin, smallest_index-1);

}

int main(){
    int n;
    scanf("%d", &n);
    int aux;
    set< pair<int, int>> s;
    for(int i = 0; i < n; i++){
        scanf("%d", &aux);
        s.insert({aux, i});
    }
    find_solution(s , n, 0, n-1);
    printf("%d", biggest_prod);

    return 0;
}

