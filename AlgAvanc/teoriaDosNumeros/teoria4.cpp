//
// Created by Yann on 15/12/2021.
//

#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull findGCD(ull a, ull b){
    if(b == 0)
        return a;
    return findGCD(b, a%b);
}

ull findLCM(ull a, ull b){
    return a*b/findGCD(a, b);
}

int main(){
    int n_tests;
    ull a, b, gcd, lcm;
    cin >> n_tests;
    for(int z = 0; z < n_tests; z++){
        cin >> a >> b;
        gcd = findGCD(a, b);
        lcm = findLCM(a, b);
        if(a != gcd and b != lcm)
            cout << "-1" << endl;
        else
            cout << gcd << " " << lcm << endl;
    }

    return 0;
}