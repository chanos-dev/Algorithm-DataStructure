#include <bits/stdc++.h>
using namespace std;

long long dp[91];

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; cin>>n;

    dp[1] = 1;
    dp[2] = 1;

    for(int i=3; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    cout<<dp[n];
}