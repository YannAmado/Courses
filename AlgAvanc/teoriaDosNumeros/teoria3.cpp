//
// Created by Yann on 13/12/2021.
//

#include <iostream>
#include <vector>


using namespace std;

#define NUMBERTODIVIDE 131071
#define ARRAY_SIZE 10000

int mod_results[ARRAY_SIZE];

void find_mod_results(){
    mod_results[0] = 1%NUMBERTODIVIDE;
    for(int i = 1; i < ARRAY_SIZE; i++)
        mod_results[i] = (mod_results[i-1]*2)%NUMBERTODIVIDE;
}

bool check_division(vector<int> bin){
    if(bin.size() == 1 and bin[0] == 0)
        return true;
    int result = 0;
    for(int i = 0; i < (int)bin.size(); i++){
        result = (result + bin[i]*mod_results[i])%NUMBERTODIVIDE;
    }
    if(result == 0)
        return true;
    return false;
}

int main(){
    vector<int> bin;
    string bin_str;
    find_mod_results();
    while(cin >> bin_str){
        //-1 to remove #
        bin.clear();
        for(int i = (int)bin_str.size()-2; i >= 0; i--){
            bin.push_back(bin_str[i]-'0');
        }
        if(check_division(bin))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}