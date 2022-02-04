#include<bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int ddx[4][4] = { {0, 0, 0, 1}, {-1, 0, 0, 1}, {0, 0, -1, 0}, {0, -1, 0, 1} };
int ddy[4][4] = { {-1, 0, 1, 0}, {0, 0, 1, 0}, {-1, 0, 0, 1}, {-1, 0, 0, 0} };

int board[501][501];
bool vist[501][501];
int n, m; 
int v;

bool out(int i, int j)
{
    return i < 0 || i >= n || j < 0 || j >= m;
}

void dfs(int i, int j, int k, int n)
{
    if (k == 4)
    {
        v = max(v, n);
        return;
    }

    for(int d=0;d<4;d++)
    {
        int nx = i + dx[d];
        int ny = j + dy[d];

        if (out(nx,ny)) continue;
        if (vist[nx][ny]) continue;

        vist[nx][ny] = true;
        dfs(nx, ny, k+1, n+board[nx][ny]);
        vist[nx][ny] = false;
    }
}

void oh(int i, int j)
{
    for(int d=0; d<4; d++)
    {
        int sum = 0;
        for(int dd=0; dd<4; dd++)
        {
            int nx = i + ddx[d][dd];
            int ny = j + ddy[d][dd];

            if (out(nx, ny)) break;

            sum += board[nx][ny];
        }

        v = max(v, sum);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>board[i][j];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            vist[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            oh(i, j);
            vist[i][j] = false;
        }
    
    cout<<v;
}