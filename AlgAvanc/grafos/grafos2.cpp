//
// Created by Yann on 20/11/2021.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define VISITED 1
#define NOTVISITED 0

using namespace std;

bool BFS(int adj_list[400][400], int n_stations, int root){
    int nodes_status[400] = {0};
    queue<int> q;
    nodes_status[root] = VISITED;
    q.push(root);
    while(q.empty() == false){
        for(int j = 0; j < n_stations; j++){
            if(nodes_status[j] != VISITED and adj_list[q.front()][j] > 0){
                q.push(j);
                nodes_status[j] = VISITED;
            }
        }
        q.pop();
    }

    for(int i = 0; i < n_stations; i++){
        if(nodes_status[i] == NOTVISITED)
            return false;
    }
    return true;
}

int find_index(string st1, vector<pair<string, int>> stations_table){
    for(int i = 0; i < (int)stations_table.size(); i++){
        if(st1 == stations_table[i].first)
            return stations_table[i].second;
    }
    return -1;
}

bool isInArray(int a, vector<int> arr){
    for(int i = 0; i < (int)arr.size(); i++){
        if (arr[i] == a)
            return true;
    }
    return false;
}

int find_min_el(int arr[400], int n_stations, vector<int> arvore){
    int min = INT32_MAX;
    int w = -1;
    for(int i = 0; i < n_stations; i++){
        if(arr[i] < min and arr[i] > 0 and isInArray(i, arvore) == false){
            min = arr[i];
            w = i;
        }
    }
    return w;
}

int find_min_cost(int start, int adj_list[400][400], int n_stations){
    if(BFS(adj_list, n_stations, start) == false)
        return -1;
    vector<int> arvore;
    int total = 0;
    int min, ww, w, u;
    w = -1;
    arvore.push_back(start);
    while((int)arvore.size() < n_stations){
        min = INT32_MAX;
        // for all elements of the spanning tree, find the smallest adjacency
        for(int z = 0; z < (int)arvore.size(); z++){
            //return to where the min adjacency is
            ww = find_min_el(adj_list[arvore[z]], n_stations, arvore);
            if(ww > -1 and adj_list[arvore[z]][ww] < min){
                min = adj_list[arvore[z]][ww];
                w = ww;
                u = arvore[z];
            }
        }
        arvore.push_back(w);
        if(w == -1)
            return -1;
        total += adj_list[u][w];
        adj_list[u][w] = -1;
        adj_list[w][u] = -1;
    }
    return total;
}

int find_on_table(string station, vector<pair<string, int>> stations_table){
    pair<string, int> p;
    for(int i = 0; i < (int)stations_table.size(); i++){
        p = stations_table[i];
        if(p.first == station)
            return p.second;
    }
    return -1;
}

int main(){
    int n_stations, n_adj;
    cin >> n_stations >> n_adj;
    int adj_list[400][400] = {0};
    vector<pair<string, int>> stations_table;
    string st1, st2, start;
    int weight, result, s;
    int st1_index, st2_index;
    while(n_stations > 0 or n_adj > 0){
        for(int i = 0; i < n_stations; i++){
            cin >> st1;
            stations_table.push_back(make_pair(st1, i));
        }
        for(int i = 0; i < n_adj; i++){
            cin >> st1 >> st2 >> weight;
            st1_index = find_index(st1, stations_table);
            st2_index = find_index(st2, stations_table);
            adj_list[st1_index][st2_index] = weight;
            adj_list[st2_index][st1_index] = weight;
        }
        cin >> start;
        s = find_on_table(start, stations_table);
        result = find_min_cost(s, adj_list, n_stations);
        if(result > -1)
            cout << result << endl;
        else
            cout << "Impossible" << endl;
        stations_table.clear();
        memset(adj_list, 0, sizeof(adj_list));
        cin >> n_stations >> n_adj;
    }
    return 0;
}