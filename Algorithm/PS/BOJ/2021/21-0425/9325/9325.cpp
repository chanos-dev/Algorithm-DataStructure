#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 
    
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
        int m, on;
        cin>>m;        
        cin>>on;

        for(int j=0; j<on; j++)
        {
            int q, p;
            cin>>q>>p;
            m += q*p;
        }

        cout<<m<<"\n";
    }
}