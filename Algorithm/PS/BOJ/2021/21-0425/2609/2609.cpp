#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int f, s;    
    cin>>f>>s; 

    int tf = f;
    int ts = s;
    int t = 0;

    while(ts)
    {
        t = tf % ts;
        tf = ts;
        ts = t;
    } 

    cout<<tf<<"\n"<<f*s/tf;
} 