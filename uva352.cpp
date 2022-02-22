#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n = 0;
int noNaves = 0;
int cont = 0;
int img[30][30], bool visited[30][30];

bool go(int row, int col, bool valid){
    bool pixel = true;

    cont++;
    if(row > n || col > n){
        return false;
    }
    if(visited[row][col]){
        return false;
    }

    visited[row][col] = true;
    if(!valid){
        if(img[row][col]){
            pixel = true;
        }
        else{
            pixel = false;
        }
    }
    else{
        if(img[row][col]){
            pixel = true;
        }
        else{
            if(cont == 8){
                noNaves++;
                cont = 0;
            }
            pixel = false;
        }
    }

    return go(row, col+1, pixel, img, visited)
        && go(row+1, col+1, pixel, img, visited)
        && go(row+1, col, pixel, img, visited)
        && go(row+1, col-1, pixel, img, visited)
        && go(row, col-1, pixel, img, visited)
        && go(row-1, col-1, pixel, img, visited)
        && go(row-1, col, pixel, img, visited)
        && go(row-1, col+1, pixel, img, visited);

}

int main()
{
    n = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> img[i][j];
        }
    }
    go(0,0,0,img);
    cout << noNaves;

    return 0;
}
