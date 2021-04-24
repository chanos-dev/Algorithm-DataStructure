#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;

    cin>>n;

    int m = n-1;

    for(int i=0; i<n; i++, cout<<"\n")
    {
        for(int j=0; j<n*2-1; j++)
        {
            if ( (j == m - i) || (j == m + i) ) 
            {
                cout<<"*";
                if (j >= m+1 || i == 0) break;
            }
            else cout<<" ";
        }        
    }
}