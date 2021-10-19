#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    set<int> s;
    s.insert(s1);
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);
    /* s.push_back(s4); */
    /* s.push_back(s2); */
    /* s.push_back(s3); */
    /* s.push_back(s4); */
    /* int cont= 0; */
    /* for(int i = 0 ; i < 4; i++){ */
    /*     for (int j = i+1 ; j< 4; j++){ */
    /*         if(s[i] == s[j] && s[i] != 0 && s[j] != 0){ */
    /*             cont ++; */
    /*             s[j] = 0; */
    /*         } */
    /*     } */
    /* } */
    /* cout<< cont; */
    cout << 4-s.size();
    return 0;
}
