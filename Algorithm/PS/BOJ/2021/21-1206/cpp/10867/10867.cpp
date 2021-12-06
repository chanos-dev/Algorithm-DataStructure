#include <bits/stdc++.h>
using namespace std; 

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    
    set<int> s;  

    int n; cin>>n;
    for(int i=0; i<n; i++)
    {
        int v; cin>>v;

        s.insert(v);
    }
    
    for (int i : s)
    {
        cout<<i<<" ";
    }
}