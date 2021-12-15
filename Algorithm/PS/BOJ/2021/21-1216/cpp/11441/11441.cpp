#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; cin>>n;

    int N[n] = {0,};
    int sum[n] = {0,};

    for(int i=0; i<n; i++)
    {
        cin>>N[i];

        if (i == 0) sum[0] = N[i];
        else sum[i] = sum[i-1] + N[i];
    } 

    int m; cin>>m;
    
    for(int t=0; t<m; t++)
    {
        int i, j; cin>>i>>j; 
        i--; j--;
        cout<<sum[j]-sum[i-1]<<"\n";
    }
}