#include <bits/stdc++.h>
using namespace std;

int main()
{    
    int t; cin>>t; 

    for(int i=0; i<t; i++)
    {
        int M[500] = {0,};
        int p, m;
        cin>>p>>m;

        for(int j=0; j<p; j++)
        {
            int n; cin>>n;
            
            M[n-1]++;
        }

        int sum = 0;

        for(int j=0; j<m; j++)
        {
            if (M[j] - 1 > 0)
            {
                sum += M[j]-1;
            }
        }

        cout<<sum<<"\n";
    }
}