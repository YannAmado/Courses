//
// Created by Yann on 22/10/2021.
//

#include <iostream>

#define ARRAY_SIZE 10000

using namespace std;

int burgers_eaten_per_time[ARRAY_SIZE] = {-1};
int remaining_time[ARRAY_SIZE] = {-1};


int find_max_burgers(int times[], int total_time){
    int smallest_time = min(times[0], times[1]);

    //initializng the vectors
    for(int i = 0; i < smallest_time; i++){
        burgers_eaten_per_time[i] = 0;
        //until the smallest time, all time will be wasted
        remaining_time[i] = i;
    }

    //ordering the times in descending order in order
    if(times[1] > times[0]){
        int aux = times[1];
        times[1] = times[0];
        times[0] = aux;
    }

    for(int i = smallest_time; i <= total_time; i++){
        remaining_time[i] = INT32_MAX;
        for(int j = 0; j < 2; j++){
            if(times[j] <= i){
                remaining_time[i] = min(remaining_time[i], remaining_time[i-times[j]]);

                //the time has to be in descending order because of this
                //if both times result in the same remaining time, the last iteration will be the one considered
                //this will result in a bigger result overall (because the last one will always have more burgers)
                if(remaining_time[i] == remaining_time[i-times[j]])
                    burgers_eaten_per_time[i] = burgers_eaten_per_time[i-times[j]];
            }
        }

        //if the remaining time is 0, its because another burger can be added
        if(remaining_time[i] == 0)
            burgers_eaten_per_time[i] += 1;
        //if no burgers can be added
        if(remaining_time[i] > 0)
            burgers_eaten_per_time[i] = burgers_eaten_per_time[i-1];
    }
    if(remaining_time[total_time] == 0)
        cout << burgers_eaten_per_time[total_time] << endl;
    else
        cout << burgers_eaten_per_time[total_time] << " " << remaining_time[total_time] << endl;
    return burgers_eaten_per_time[total_time];

}

int main(){
    int minutes;
    int times[2];
    while(scanf("%d", &times[0]) != EOF){
        scanf("%d %d", &times[1], &minutes);
        find_max_burgers(times, minutes);
    }
    return 0;
}