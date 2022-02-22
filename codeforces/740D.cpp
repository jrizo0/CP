#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair

int c;
vector<int> tree;
vector<pii> adj;
vector<int> dist;

vector<int> hijos(int s){
    vector<int> res;
    for(int i = 2 ; i <= c ; i++){
        /* cout << adj[i].first << " "; */
        if(adj[i].first == s && s != i){
            res.push_back(i);
        }
    }
    for(int i = 0 ; i < res.size(); i++){
        /* cout << res[i] << " "; */
    }
    /* cout << endl; */
    return res;
}

void dfs(int s, int e){
    cout << s << "  ";
    dist[s] = 1;
    for(auto u: hijos(s)){
        if(u == e)
            continue;
        dfs(u,s);
        dist[s] += adj[u].second;
    }
}

/* int dist(int v, int u){ */

/* } */

int main()
{
    cin >> c;
    tree.push_back(0);
    for(int i = 1 ; i <= c ; i++){
        int x;
        cin >> x;
        tree.push_back(x);
        dist.push_back(0);
    }
    adj.push_back(mp(0,0));
    adj.push_back(mp(0,0));
    for(int i = 2 ; i <= c ; i++){
        int x, y;
        cin >> x >> y;
        adj.push_back(mp(x,y));
    }
    /* for(int i = 2 ; i <= c; i++) */
    /* { */
    /*     cout << adj[i].first << "," << adj[i].second << " "; */
    /*     /1* cout << tree[i] << " "; *1/ */
    /* } */

    dfs(3,1);

    for(int i = 1; i <= c; i++)
    {
        cout << dist[i] << " ";
        /* cout << adj[i].first << "," << adj[i].second << " "; */
        /* cout << tree[i] << " "; */
    }
    return 0;
}
