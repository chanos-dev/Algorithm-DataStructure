#include<bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int board[101][101];
int vist[101][101][1001];
int n, m; 
int ans = 1001;

bool out(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= m;
}

void algospot()
{
    queue<pair<pair<int, int>,int>> q;
    q.push({{0, 0}, 0});

    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int b = q.front().second;
        q.pop();

        if (x == n-1 && y == m-1)
        {
            ans = min(ans, b);
            continue;
        }

        for(int d=0; d<4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (out(nx, ny)) continue;            

            if (b <= 1000 && board[nx][ny] == 1 && !vist[nx][ny][b+1])
            {
                vist[nx][ny][b+1] = vist[x][y][b]+1;
                q.push({{nx,ny}, b+1});
            }
            else if (board[nx][ny] == 0 && !vist[nx][ny][b])
            {
                vist[nx][ny][b] = vist[x][y][b]+1;
                q.push({{nx,ny}, b});
            }
        }
    }
}

int main()
{
    cin>>m>>n;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            char c; cin>>c;
            board[i][j] = c - '0';
        }

    algospot();
    cout<<ans;
}