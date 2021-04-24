#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;
    int m;
    cin>>n;
    m = 1;
    for(int i=0; i<n*2-1; i++)
    {        
        for(int j=0; j<n; j++)
        {
            if ((n-m) > j) cout<<" ";
            else cout<<"*";
        }

        cout<<"\n";

        if (i < n-1) m++;
        else m--;
    }
}