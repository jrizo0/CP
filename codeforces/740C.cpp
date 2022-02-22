#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> sub; 
    int minimum=int (1e9) + 5;
    for(int i = 0 ; i < m ; i++){
        int l,r;
        cin >> l >> r;
        sub.push_back(make_pair(l,r));
        minimum = min(minimum, r-l+1);
    }
    cout << minimum << endl;
    int cont = 0; 
    /* cout << minimum << " "; */
    for(int i = 0 ; i < n; i++){
        cout << cont << " ";
        cont ++;
        if(cont >= minimum){
            cont = 0 ;
        }
    }
    return 0;
}
