#include <bits/stdc++.h>
using namespace std; 

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    
    int n; cin>>n;
    int* P = new int[n]();

    for(int i=0;i<n;i++)
    {
        int v; cin>>v;
        P[i] = v;
    }

    sort(P, P+n);

    int m = 0;
    int s = 0;
    for(int i=0; i<n; i++)
    {
        m += P[i];
        s += m;
    }

    cout<<s;
}