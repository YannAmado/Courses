//
// Created by Yann on 14/10/2021.
//

#include <iostream>
#include <vector>

using namespace std;

bool isTooBig(vector<int> containers, int vessel_size, int n_vessels){
    int vessels_used = 1;
    int current_vessel = 0;
    for(int i = 0; i < (int)containers.size(); i++){
        current_vessel += containers[i];
        //if a single vessel cant fit a single container, is because its too small
        if(vessel_size < containers[i])
            return false;

        //if the current vessel cant handle more milk
        if(current_vessel > vessel_size){
            current_vessel = containers[i];
            vessels_used++;
        }

        //if theres an exact quantity
        if(current_vessel == vessel_size){
            current_vessel = 0;
            vessels_used++;
        }
    }
    //if a new vessel was prepared but not used
    if(current_vessel == 0)
        vessels_used--;
    if(vessels_used > n_vessels)
        return false;
    return true;
}

int bin(vector<int> containers, int n_vessels, int begin, int end){
    if(begin == end)
        return begin;
    if(end-begin == 1){
        if(isTooBig(containers, begin, n_vessels) == false)
            return end;
        return begin;
    }
    int mid = (end + begin)/2;
    if(isTooBig(containers, mid, n_vessels) == true)
        return bin(containers, n_vessels, begin, mid);
    return bin(containers, n_vessels, mid, end);
}

int main(){
    int n_containers, n_vessels, aux;
    vector<int> containers;
    while(scanf("%d", &n_containers) != EOF){
        scanf("%d", &n_vessels);
        containers.clear();
        for(int i = 0; i < n_containers; i++){
            scanf("%d", &aux);
            containers.push_back(aux);
        }
        printf("%d\n", bin(containers, n_vessels, 0, 1000000));
    }

}
