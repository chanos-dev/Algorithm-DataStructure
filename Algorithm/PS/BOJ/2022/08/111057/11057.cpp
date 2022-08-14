#include <bits/stdc++.h>
using namespace std;

int dp[1001][10];

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; cin>>n;
    
    for(int i=0; i<10; i++)
        dp[0][i] = 1;

    for(int i=0; i<n; i++)
        dp[i][9] = 1;

    int mod = 10007;

    for(int i=1; i<n; i++)
        for(int j=8; j>=0; j--)
            dp[i][j] = (dp[i-1][j] + dp[i][j+1]) % mod;

    int ans = 0;
    for(int i=0; i<10; i++)
        ans = (ans + dp[n-1][i]) % mod;

    cout<<ans;
}