#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<math.h>
#include<map>
#include<stack>
#include<sstream>
#include<queue>
#include<list>
#include<iomanip>
#include<bitset>
#include<limits.h>
#define INF  -1
#define MOD  1000000007
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define MP(a,b) make_pair(a,b)
#define fr first
#define sc second
using namespace std;
 
//--------------------- This code Written by " Abanob Ashraf " ----------------------------------
//------------------ I Hope To Learn Or Understand Any Thing from it ----------------------------
//----------------------------------- START -----------------------------------------------------
 
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
 
    int N , M ;
 
    scanf("%d%d" , &N , &M) ;
 
    //inicializa un vector de sets representando las adyacencias
    //[set0, ...., setn]
    vector< set<int> > tie (N + 1) ;

    int a , b ;
 
    while (M--)
    {
        scanf("%d%d" , &a , &b) ;
        //inserta las adyacencias para ambos estudiantes
        tie [a].insert(b) ;
        tie [b].insert(a) ;
    }
 
 
    int groups = 0 ;
 
    while (1)
    {
        vector<int> v ;
 
        for (int i = 1 ; i <= N ; i++)
        {
            //si el estudiante i tiene solo una conexion, lo guarda en v
            if (tie [i].size() == 1)
                v.push_back(i) ;
        }
 
        for (int i = 0 ; i < (int) v.size() ; i++)
        {
            //it apunta a la primera de las adyacencias de v[i] que esta en un set
            set<int>::iterator it = tie [ v[i] ].begin() ;
            tie [ v[i] ].clear() ; //borra todas las adyacencias de v[i] que solo es una
            tie [ *it ].erase(v[i]) ; //borra las adyacencias del otro estudiante que estaba conectado con v[i]
        }

        //si v no esta vacio groups ++
       if (v.size())
            groups++ ;
       else
            break ;
    }
 
    printf("%d" , groups ) ;
 
}
//------------------------------------ DONE -----------------------------------------------------
