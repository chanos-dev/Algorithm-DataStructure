#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int T;
    cin>>T;

    for(int i=0; i<T; i++)
    {
        int v,e;
        cin>>v>>e;
        cout<<2+e-v;
    }
}