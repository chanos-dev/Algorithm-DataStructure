#include <bits/stdc++.h>
using namespace std;

int n, m; 
int board[501][501];
int dp[501][501];

int ans = 0;

int dx[] = {0, 1, 0 ,-1};
int dy[] = {1, 0, -1, 0};

int dfs(int x, int y)
{
    if (x == n-1 && y == m-1) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;

    for(int d=0; d<4; d++)
    {
        int nx = dx[d] + x;
        int ny = dy[d] + y;

        if (nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
        if (board[x][y] <= board[nx][ny]) continue;

        dp[x][y] += dfs(nx, ny);
    }

    return dp[x][y];
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    cin>>n>>m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cin>>board[i][j];
            dp[i][j] = -1;
        }
    
    cout<<dfs(0, 0);
}