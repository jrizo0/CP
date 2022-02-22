#include <bits/stdc++.h>

using namespace std;

enum status {CYCLE = 0, PATH = 1};

vector<vector<int>> graph;
vector<bool> vis;

status dfs(int curNode, int parentNode, int &contNodes){
    if(vis[curNode])
        return CYCLE;
    vis[curNode] = 1;
    for(auto childNode : graph[curNode]) if(childNode != parentNode){
        contNodes++;
        if(dfs(childNode, curNode, contNodes) == CYCLE){
            return CYCLE;
        }
    }
    //Didn't find cycle
    return PATH;
}

int main()
{
    int n, m;
    cin >> n >> m;
    graph = vector<vector<int>>(n);
    vis = vector<bool>(n);
    for(int i = 0 ; i < m ; i ++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int toRemove = 0;
    for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
            int contNodes = 0;
            status solve = dfs(i, -1, contNodes);
            if(solve == CYCLE) // if odd cycle add 1
                toRemove += (contNodes % 2 == 1) ;
        }
    }
    if((n-toRemove) % 2 == 1){
        toRemove++;
    }
    cout << toRemove;
    return 0;
}
