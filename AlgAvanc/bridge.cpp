//
// Created by Yann on 01/09/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;


void move(std::vector<int>&left,  std::vector<int>&right, int el1, int el2, string& passages,int* time){
    int pos1, pos2;
    pos1 = -1;
    for(int i = 0; i < (int)left.size(); i++){
        if(pos1 == -1 and left[i] == el1)
            pos1 = i;
        else if(left[i] == el2)
            pos2 = i;
    }
    if(el2 == -1){
        right.push_back(el1);
        std::sort(right.begin(), right.end());
        left.erase(left.begin() + pos1);
        passages += to_string(el1) + "\n";
        *time += el1;
        return;
    }
    right.push_back(el1);
    right.push_back(el2);
    std::sort(right.begin(), right.end());
    left.erase(left.begin() + pos1);
    left.erase(left.begin() + pos2-1);
    *time += el2;
    passages += to_string(el1) + " " + to_string(el2) + "\n";
}


void bridge_crosser(std::vector<int> people, int n_people){
    std::vector<int> left;
    std::vector<int> right;
    int time = 0;
    std::string passages = "";
    std::string right_p = "";
    if(n_people == 1){
        printf("%d\n%d\n", people[0], people[0]);
        return;
    }
    for(int i = 0; i < n_people; i++)
        left.push_back(people[i]);
    int fastest_time = left[0];
    int sec_fastest_time = left[1];
    while(left.size() > 2){
        if(left.size() > 2 and ((2*fastest_time + left.back() + left[left.size()-2]) < (2*sec_fastest_time + fastest_time + left.back()))){
            move(left, right, left[0], left[left.size()-2], passages, &time);
            move(right, left, right[0], -1, passages, &time);
            move(left, right, left[0], left.back(), passages, &time);
            if(left.size() > 0)
                move(right, left, right[0], -1, passages, &time);
        }
        else{
            move(left, right, left[0], left[1], passages, &time);
            move(right, left, right[0], -1, passages, &time);
            move(left, right, left[left.size()-2], left.back(), passages, &time);
            move(right, left, right[0], -1, passages, &time);
        }

    }
    if(left.size() == 1)
        move(left, right, left[0], -1, passages, &time);
    else if(left.size() == 2)
        move(left, right, left[0], left[1], passages, &time);

    printf("%d\n", time);
    std::cout << passages;
}

int main(){
    int n_cases;
    int n_people;
    std::vector<int> people;
    int person;
    scanf("%d", &n_cases);
    for(int z = 0; z < n_cases; z++){
        scanf("%d", &n_people);
        for(int i = 0; i < n_people; i++){
            scanf(" %d", &person);
            people.push_back(person);
        }
        std::sort(people.begin(), people.end());
        bridge_crosser(people, n_people);
        if(z < n_cases-1)
            printf("\n");
        people.clear();
    }
    return 0;
}