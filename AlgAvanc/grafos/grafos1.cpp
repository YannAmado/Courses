//
// Created by Yann on 18/11/2021.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define VISITED 1
#define NOTVISITED 0

typedef pair<int,int> ii;
typedef vector<ii> vii;

bool BFS(vector<vii> adj_list, set<int> nodes, int root){
    int nodes_status[10000] = {0};
    queue<int> q;
    q.push(root);
    int v;
    int current_node;
    nodes_status[root%10001] = VISITED;
    while(q.empty() == false){
        current_node = q.front();
        q.pop();
        for(int i = 0; i < (int)adj_list[current_node%10001].size(); i++){
            v = adj_list[current_node%10001][i].second;
            if(nodes_status[v%10001] == VISITED)
                return false;
            q.push(v);
            nodes_status[v%10001] = VISITED;
        }
    }
    for(auto i = nodes.begin(); i != nodes.end(); i++){
        if(nodes_status[(*i)%10001] == NOTVISITED)
            return false;
    }
    return true;
}

bool isTree(vector<vii> adj_list, set<int> nodes){
    int nodes_status[10000] = {0};
    ii par;
    int v;
    //push the 0 node that does not exist, is only pushed to make it easier the array op
    //i.e, its possible to check the node i status by only node[i]
    for(auto i = nodes.begin(); i != nodes.end(); i++){
        for(int j = 0; j < (int)adj_list[(*i)%10001].size(); j++){
            par = adj_list[(*i)%10001][j];
            v = par.second;
            if(par.first == par.second)
                return false;
            if(nodes_status[v%10001] == NOTVISITED)
                nodes_status[v%10001] = VISITED;
            else
                return false;
        }
    }
    //verifying how many roots exist
    int n_roots = 0;
    int root;
    for(auto i = nodes.begin(); i != nodes.end(); i++){
        if(nodes_status[(*i)%10001] == NOTVISITED){
            n_roots++;
            root = (*i)%10001;
        }
    }
    if(n_roots > 1)
        return false;
    return BFS(adj_list, nodes, root);
}



int main(){
    vector<vii> adj_list(10000);
    set<int> nodes;
    int u, v, i;
    u = 0; v = 0; i = 1;
    cin >> u >> v;
    while(u > -1){
        while(u > 0){
            adj_list[u%10001].push_back(make_pair(u,v));
            nodes.insert(u);
            nodes.insert(v);
            cin >> u >> v;
        }
        if(isTree(adj_list, nodes) == true)
            cout << "Case " << i << " is a tree." << endl;
        else
            cout << "Case " << i << " is not a tree." << endl;
        for(auto j = nodes.begin(); j != nodes.end(); j++)
            adj_list[(*j)%10001].clear();
        nodes.clear();
        i++;
        cin >> u >> v;
    }


    return 0;
}
