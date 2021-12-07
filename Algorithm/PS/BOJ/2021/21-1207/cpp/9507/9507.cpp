#include <bits/stdc++.h>
using namespace std; 
 
int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    
    int n; cin>>n;
    long long int dp[69] = {0,};

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i=4; i <70; i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
    }


    for(int i=0; i<n; i++)
    {
        int p; cin>>p;
        cout<<dp[p]<<"\n";
    }
}