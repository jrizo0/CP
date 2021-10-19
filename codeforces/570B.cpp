#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , m, a;
    cin >> n, m;
    int cont[n];
    for(int i = 0; i < n; i++){
        cont[i] = 0;
    }
    for(int i = 0; i < n ; i++){
        if(i != m-1)
        for(int j = 0; j < n ; j++){
            if(j != m-1 && abs(j-i) < abs(i -m-1)){
                cont[j] ++;
            }
        }
    }

    int max = -1;
    for(int i = 0; i < n ; i++){
        if(cont[i] > max)
            max = i;
        cout << cont[i] << " ";
    }
    cout << max + 1;
    return 0;
}
