#include <bits/stdc++.h>
using namespace std;

int dp[101][11];

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    int n; cin>>n;
    long mod = 1'000'000'000;

    // init
    for(int i=0; i<10; i++)
        dp[1][i] = 1;
    
    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<10; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i-1][j+1];
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];

            dp[i][j] %= mod;
        }
    }

    int ans = 0;
    for(int i=1; i<10; i++)
        ans = (ans + dp[n][i]) % mod;
    
    cout<<ans;
}