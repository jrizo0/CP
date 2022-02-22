#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc, x;
    float num, n, f;
    bool hasDecimal; 
    cin >> tc;
    for(int i = 0; i < tc; i++){
        cin >> num;
        f = num / 180.0;
        n = 2 / (1 - f);
        hasDecimal = ((int)(round(n*100)) % 100) != 0;
        if(hasDecimal)
            cout << "NO" << endl;
        else 
            cout << "YES" << endl;
    }
    return 0;
}
