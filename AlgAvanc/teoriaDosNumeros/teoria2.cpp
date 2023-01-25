//
// Created by Yann on 11/12/2021.
//

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
#define tamCrivo INT32_MAX
#define PRIME 1
#define NOTPRIME 0


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


bool find_if_divides(ull fact_num, ull num_to_divide){
    if(crivo[num_to_divide] == PRIME and num_to_divide > fact_num)
        return false;


    vector<int> dec_num_to_divide = decompose(num_to_divide);
    sort(dec_num_to_divide.begin(), dec_num_to_divide.end(), greater<int>());
    for(int i = fact_num; i > 0; i--){
        vector<int> dec_fact_num = decompose(i);
        sort(dec_fact_num.begin(), dec_fact_num.end(), greater<int>());
        while(dec_fact_num.size() > 0){
            for(int i = 0; i < (int)dec_num_to_divide.size(); i++){
                if(dec_fact_num.back() == dec_num_to_divide[i]){
                    dec_num_to_divide[i] = 0;
                    break;
                }
            }
            dec_fact_num.pop_back();
        }
        while(dec_num_to_divide.size() > 0 and dec_num_to_divide.back() == 0)
            dec_num_to_divide.pop_back();
        if(dec_num_to_divide.size() == 0)
            return true;
    }
    return false;

}

int main(){
    ull fact_num, num_to_divide;
    find_prime_numbers();
    bool divides;
    while(cin >> fact_num >> num_to_divide){
        divides = find_if_divides(fact_num, num_to_divide);
        if(divides == true)
            cout << num_to_divide << " divides " << fact_num << "!" << endl;
        else
            cout << num_to_divide << " does not divide " << fact_num << "!" << endl;
    }
    return 0;
}