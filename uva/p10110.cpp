#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin >> n && n != 0){
        int sq = (int)sqrt(n);
        cout << (sq * sq == n?"yes\n": "no\n");
    }
    return 0;
}
