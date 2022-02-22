#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc, x1l, y1l, x1r, y1r, x2l, y2l, x2r, y2r, xlo, ylo, xro, yro;
    cin >> tc;

    for(int i = 0 ; i < tc ; i++){
        cin >> x1l >> y1l >> x1r >> y1r >> x2l >> y2l >> x2r >> y2r;

        xlo = max(x1l, x2l);
        ylo = max(y1l, y2l);
        xro = min(x1r, x2r);
        yro = min(y1r, y2r);

        if(i > 0) 
            cout << endl;

        if(xlo < xro && ylo < yro)
            cout << xlo << " " << ylo << " " << xro << " " << yro << endl;
        else
            cout << "No Overlap" << endl;
    }

    return 0;
}
