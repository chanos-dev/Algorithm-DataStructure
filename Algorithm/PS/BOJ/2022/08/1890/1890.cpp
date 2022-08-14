#include <bits/stdc++.h>
using namespace std;

int board[101][101];
long long dp[101][101];

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>board[i][j];
    
    dp[0][0] = 1;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if (dp[i][j] == 0 || board[i][j] == 0) continue;

            int m = board[i][j];

            if (j+m < n) dp[i][j+m] += dp[i][j];            
            if (i+m < n) dp[i+m][j] += dp[i][j];
        }
    } 

    cout<<dp[n-1][n-1];
}