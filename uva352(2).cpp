#include <bits/stdc++.h>

using namespace std;

char img[30][30];
bool visited[30][30];
int n;

int dx[8] = {0,0,1,-1,1,-1,1,-1};
int dy[8] = {1,-1,0,0,1,-1,-1,1};

bool posValid(int row, int col){
    return row >= 0 && col >= 0 && row < n && col < n;
}

void dfs(int row, int col){
    if(visited[row][col]){
        return;
    }
    visited[row][col] = 1;
    for(int i = 0 ; i < 8; i++){
        int newx = dx[i] + row; 
        int newy = dy[i] + col; 
        if(posValid(newx, newy) && !visited[newx][newy] && img[newx][newy] == '1')
            dfs(newx, newy);
    }
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> img[i][j];
        }
    }
    /* while(scanf("%d", &n) != EOF){ */
    /*     for(int i = 0 ; i < n; i++){ */
    /*         scanf("%s", img[i]); */
    /*     } */
    /* } */
    memset(visited, 0, sizeof(visited));
    int cont = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(!visited[i][j] && img[i][j] == '1'){
                dfs(i,j);
                cont++;
            }
        }
    }
    cout << "Image number 1 contains "<< cont <<  " war eagles.";
    return 0;
}
