#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<pair<int, int>> virus;
int board[9][9];
int n, m;
int ans = -1;

void spread()
{
    queue<pair<int, int>> q;
    for(pair<int, int> v : virus)
        q.push(v);
    
    int map[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            map[i][j] = board[i][j];

    while(!q.empty())
    {
        pair<int, int> p = q.front(); q.pop();

        for(int d=0; d<4; d++)
        {
            int nx = p.x + dx[d];
            int ny = p.y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (map[nx][ny] != 0) continue;

            map[nx][ny] = 2;
            q.push({nx, ny});
        }
    }

    int z = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if (map[i][j] == 0) 
                z++;
        }
    
    if (ans < z)
        ans = z;
}

void wall(int k)
{
    if (k == 3)
    {
        spread();
        return;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if (board[i][j] != 0) continue;
            
            board[i][j] = 1;
            wall(k+1);
            board[i][j] = 0;
        }
    }
}

int main()
{
    cin>>n>>m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cin>>board[i][j];
            if (board[i][j] == 2)
                virus.push_back({i, j});
        }
    
    wall(0);
    cout<<ans;
}