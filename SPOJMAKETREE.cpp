#include <bits/stdc++.h>

using namespace std;

enum status {CYCLE = 0, PATH = 1};

vector<bool> vis;
vector<vector<int>> ady;
int parent[100000];
vector<int> initialResult;

void topologycalSort(int student){
    vis[student] = 1;
    for(int i = 0; i < ady[student].size(); i++){
        int child = ady[student][i];
        if(!vis[child]){
            topologycalSort(child);
        }
    }
    initialResult.push_back(student);
}

int main()
{
    int n, k;
    cin >> n >> k;
    ady = vector<vector<int>>(n+1);
    vis = vector<bool>(n+1);
    for(int i = 1 ; i <= k; i++){
        int cant;
        cin >> cant;
        while(cant--){
            int x;
            cin >> x;
            ady[i].push_back(x);
        }
    }

    for(int i = 1 ; i <= n ; i++){
        if(!vis[i])
            topologycalSort(i);
    }

    int position = 0;
    for(int i = n -1 ; i >= 0 ; i--){
        int student = initialResult[i];
        parent[student] = position;
        position = student;
    }

    for(int i = 0 ; i < n ; i++){
        cout << parent[i] << endl;
    }

    return 0;
}
