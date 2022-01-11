#include<bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1 ,0};
int dy[] = {0, 1, 0, -1};

int board[1001][1001];
int vist[1001][1001][11];

#define x first
#define y second

int main()
{
    int n, m, k; cin>>n>>m>>k;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            char c; cin>>c;
            board[i][j] = c-'0';
        }
    
    queue<pair<pair<int, int>, int>> q;

    q.push({{0, 0}, k});
    vist[0][0][k] = 1;

    while(!q.empty())
    {
        int px = q.front().first.first;
        int py = q.front().first.second;
        int wall = q.front().second;
        q.pop();

        if (px == n-1 && py == m-1)
        {
            cout<<vist[px][py][wall];
            return 0;
        }

        for(int d=0; d<4; d++)
        {
            int nx = px + dx[d];
            int ny = py + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (wall > 0 && board[nx][ny] == 1 && vist[nx][ny][wall-1] == 0)
            {
                q.push({{nx, ny}, wall-1});
                vist[nx][ny][wall-1] = vist[px][py][wall] + 1;
            }
            else if (board[nx][ny] == 0 && !vist[nx][ny][wall])
            {
                q.push({{nx, ny}, wall});
                vist[nx][ny][wall] = vist[px][py][wall] + 1;
            }
        }
    } 

    cout<<"-1";
}