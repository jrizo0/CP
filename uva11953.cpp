#include <bits/stdc++.h>

using namespace std;

bool visited[100][100];
char grid[100][100];
int n;

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

bool alive = false;

bool valid(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < n;
}

void dfs(int i, int j){
    if(visited[i][j]){
        return;
    }
    visited[i][j] = 1;
    if(!alive){
        if(grid[i][j] == 'x')
            alive = true;
    }
    for(int k = 0; k < 4; k++){
        int ci = i + di[k];
        int cj = j + dj[k];
        if(valid(ci, cj) && (grid[ci][cj] == 'x' || grid[ci][cj] == '@')){
            dfs(ci, cj);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> n;
        memset(visited, 0, sizeof(visited));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> grid[i][j];
            }
        }
        int cont = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(!visited[i][j]){
                    if(grid[i][j] == 'x'){
                        alive = true;
                        dfs(i, j);
                        if(alive)
                            cont++;
                    }
                    else if(grid[i][j] == '@'){
                        alive = false;
                        dfs(i, j);
                        if(alive)
                            cont++;
                    }
                }
            }
        }
        cout << "Case " << tc << ": " << cont << endl;
    }
    return 0;
}
