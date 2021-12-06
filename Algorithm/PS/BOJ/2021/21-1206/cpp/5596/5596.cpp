#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    
    int s = 0, t = 0;

    for(int i=0; i<4; i++)
    {
        int n; cin>>n;
        s += n;
    } 

    for(int i=0; i<4; i++)
    {
        int n; cin>>n;
        t += n;
    } 

    if (s > t)
        cout<<s;
    else
        cout<<t;
}