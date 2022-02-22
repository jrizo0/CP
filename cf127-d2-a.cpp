#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    double totDist = 0.0;
    int x1, y1;
    int x2, y2;
    for(int i = 0; i < n; i++){
        if(i==0){
            cin >> x1 >> y1;
        }else{
            cin >> x2 >> y2;
            /* cout << x1 << ", " << y1 << "\n" << x2 << ", " << y2 <<endl; */
            double d = ((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1));
    /* cout << d << endl; */
            d = sqrt(d);
    /* cout << d << endl; */
            totDist += d;
            x1=x2, y1=y2;
        }
    }
    /* cout << totDist << endl; */
    totDist = totDist * k;
    double res = totDist / 50.000000;
    printf("%.7lf",res);
    /* cout << (double)res; */
    return 0;
}
