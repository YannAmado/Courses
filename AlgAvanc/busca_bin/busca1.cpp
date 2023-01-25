#include <iostream>
#include <vector>

using namespace std;

int find_k(vector <int> rungs){
    int k
    ;
    int ini_k;
    k = rungs[0];
    for(int i = 1; i < (int)rungs.size(); i++){
        if(k < rungs[i] - rungs[i-1])
            k = rungs[i] - rungs[i-1];
    }
    ini_k = k;
    for(int i = 1; i < (int)rungs.size();i++){
        if(k == rungs[i] - rungs[i-1])
            k--;
        else if(k < rungs[i] - rungs[i-1]){
            k++;
            ini_k++;
        }
    }
    return ini_k;
}

int main() {
    int n_tests, n_rungs, aux;
    vector <int> rungs;
    scanf("%d", &n_tests);
    for(int z = 0; z < n_tests; z++){
        scanf("%d", &n_rungs);
        rungs.clear();
        rungs.push_back(0);
        for(int i = 0; i < n_rungs; i++){
            scanf("%d", &aux);
            rungs.push_back(aux);
        }
        printf("Case %d: %d\n", z+1, find_k(rungs));
    }
    return 0;
}
