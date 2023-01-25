//
// Created by Yann on 26/10/2021.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define ARRAY_SIZE 1000000
#define CURRENT_PLAYER 0
#define OTHER_PLAYER 1

using namespace std;


int WINNER[ARRAY_SIZE] = {0};


//If its my turn and i am on this situation
//WINNER[0] = CURRENT_PLAYER;
//WINNER[1] = CURRENT_PLAYER;
//WINNER[2] = OTHER_PLAYER;
//WINNER[3] = CURRENT_PLAYER;
//WINNER[4] = OTHER_PLAYER;
//WINNER[5] = CURRENT_PLAYER;


void find_winner(int n_stones, vector<int> moves){
    WINNER[0] = CURRENT_PLAYER;
    for(int i = 1; i <= n_stones; i++){
        WINNER[i] = OTHER_PLAYER;
        for(int j = 0; j < (int)moves.size(); j++) {
            if (i >= moves[j]) {
                //if the winner making that move is or will be the current player
                if (i - moves[j] == 0 or WINNER[i - moves[j]] == OTHER_PLAYER)
                    WINNER[i] = CURRENT_PLAYER;
            }

        }

    }
    if(WINNER[n_stones] == CURRENT_PLAYER)
        cout << "Stan wins" << endl;
    else
        cout << "Ollie wins" << endl;
}

int main(){
    int n_stones, n_moves, aux;
    vector<int> moves;
    while(scanf("%d", &n_stones) != EOF){
        cin >> n_moves;
        moves.clear();
        for(int i = 0; i < n_moves; i++){
            cin >> aux;
            moves.push_back(aux);
        }
        sort(moves.begin(), moves.end(), greater<int>());
        find_winner(n_stones, moves);
    }

    return 0;
}