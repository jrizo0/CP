#include <iostream>
#include <queue>
#include <set>
using namespace std;

#define pii pair<int, int>
#define mp make_pair

set <pii> vis;
queue< pii> q;

void markVisited(int a, int b){
    pii temp = mp(a,b);
    //si temp esta al final del set
    if(vis.find(temp) == vis.end()){
        //mete temp al set de visitados, y lo saca de la cola para no visitarlo de nuevo
        vis.insert(temp);
        q.push(temp);
    }
}

int main() {
    int t, a, b, c, newA, newB, res = 0;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        if(c > a && c > b){
            cout << -1 << endl;
            continue;
        }

        bool ckSol = false;
        res = 0;
        vis.clear();
        q = queue<pii>();
        q.push(mp(0, 0));
        vis.insert(mp(0,0));
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                pii cur = q.front();
                q.pop();
                if(cur.first  == c|| cur.second == c){
                    ckSol  = true;
                    break;
                }
                // fill a
                markVisited(a,cur.second);
                // fill b
                markVisited(cur.first,b);
                // empty a
                markVisited(0,cur.second);
                // empty b
                markVisited(cur.first,0);
                // from a to b
                newB = min (b,cur.first+cur.second);
                newA = cur.first - (newB-cur.second);
                markVisited(newA,newB);
                // from b to a
                newA = min (a,cur.first+cur.second);
                newB = cur.second - (newA-cur.first);
                markVisited(newA,newB);
            }
            if(ckSol){
                cout << res << endl;
                break;
            }
            res++;
        }
        if(!ckSol)
            cout << -1 << endl;
    }

    return 0;
}

