#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, b ,d;
    cin >> n >> b >>d;
    int rec = 0;
    int cont = 0;
    while(n--){
        int a;
        cin >> a;

        if(a <= b){
            rec += a;
        }
        if(rec > d){
            cont ++;
            rec = 0;
        }
    }
    cout << cont;
    return 0;
}
