#include <bits/stdc++.h>

using namespace std;

/* vector<vector<int>> graph; */
/* vector<bool> vis; */
/* vector<int> res; */
bool vis[150];
vector<vector<int>> graph(150);
vector<int> res;

void topSort(int node){
    vis[node] = true;

    for(int i = 0; (int)i < graph[node].size(); i++){
        int child = graph[node][i];
        if(!vis[child])
            topSort(child);
    }
    res.insert(res.begin(), node+1);
}

int main()
{
    int n, m, x, y;
    while(cin >> n >> m && n != 0){
        /* graph = vector<vector<int>>(n+1); */
        /* vis = vector<bool>(n+1); */
        res.clear();
        res.clear();
        memset(vis, false, sizeof vis);

        for(int i = 0 ; i < m ; i++){
            cin >> x >> y;
            graph[x-1].push_back(y-1);
        }

        for(int i = 0; i < n; i++){
            if(!vis[i])
                topSort(i);
        }
        for(int i = 0 ; i < (int)res.size(); i++){
            cout << res[i] << " \n"[i == (int)res.size() - 1];
        }
    }
    return 0;
}
