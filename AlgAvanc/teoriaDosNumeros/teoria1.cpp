//
// Created by Yann on 06/12/2021.
//

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
#define tamCrivo 50000


bitset<tamCrivo> crivo;
vector<int> prime_numbers;

vector<int> find_prime_numbers(){
    crivo.set();
    crivo[0] = 0;
    crivo[1] = 0;
    prime_numbers.push_back(2);
    for(int i = 3; i < tamCrivo; i++){
        if(i%2 == 0)
            crivo[i] = 0;
        else if(crivo[i] == 1){
            for(ull j = i*i; j <= (ull)crivo.size(); j += i){
                crivo[j] = 0;
            }
            prime_numbers.push_back(i);
        }
    }
    return prime_numbers;
}

vector<int> decompose(ull number){
    vector<int> decomposed_num;
    // if the number is prime

    int i = 0;
    while(number > 1 and i < (int)prime_numbers.size()){
        if(number%prime_numbers[i] == 0){
            number = number/prime_numbers[i];
            decomposed_num.push_back(prime_numbers[i]);
        }
        else
            i++;
    }
    if(number > 1)
        decomposed_num.push_back(number);
    return decomposed_num;
}

string vec_to_string(vector<int> decomposed_num){
    string str;
    for(ull i = 0; i < (ull)decomposed_num.size(); i++){
        str.append(to_string(decomposed_num[i]));
    }
    return str;
}

string findQ(long long int number){
    vector<int> decomposed_num = decompose(number);
    if(decomposed_num.size() == 0){
        if(number < 10)
            return to_string(number);
        else
            return "-1";
    }
    if(decomposed_num.back() > 10)
        return "-1";

    sort(decomposed_num.begin(), decomposed_num.end(), greater<int>());
    vector<int> min_decomposed_num;
    int i = -1;
    int j = 0;
    while(j < (int)decomposed_num.size()){
        if(min_decomposed_num.empty() == false and min_decomposed_num[i] <= 4){
            if(min_decomposed_num[i] <= 3 or (min_decomposed_num[i] == 4 and decomposed_num[j] == 2))
                min_decomposed_num[i] *= decomposed_num[j];
            else{
                min_decomposed_num.push_back(decomposed_num[j]);
                i++;
            }
        }
        else{
            min_decomposed_num.push_back(decomposed_num[j]);
            i++;
        }
        j++;
    }
    for(;j < (int)decomposed_num.size(); j++){
        min_decomposed_num.push_back(decomposed_num[j]);
    }
    sort(min_decomposed_num.begin(), min_decomposed_num.end());
    return vec_to_string(min_decomposed_num);
}



int main(){
    int z;
    ull number;
    cin >> z;
    find_prime_numbers();
    for(int i = 0; i < z; i++){
        cin >> number;
        cout << findQ(number) << endl;
    }
    return 0;
}