#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t && t <= 2 && t <= 100; i++)
    {
        ll n, m, a, d;
        cin >> n >> m >> a >> d;

        ll cont = 0;
        for (ll j = n; j <= m; j++)
        {
            if (j % a != 0 && j % (a + d) != 0 && j % (a + (2 * d)) != 0 && j % (a + (3 * d)) != 0 && j % (a + (4 * d)) != 0)
            {
                cont++;
            }
        }
        cout << cont;
    }

    return 0;
}
