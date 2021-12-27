#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char board[1000][1000];
int vist[1000][1000][2];

int main()
{
    int r,c; cin>>r>>c;

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
        {
            cin>>board[i][j];
        }
    
    queue<pair<pair<int, int>, int>> q;

    q.push({{0, 0}, 1});
    vist[0][0][1] = 1;

    while(!q.empty())
    {
        int px = q.front().first.first;
        int py = q.front().first.second;
        int wall = q.front().second;
        q.pop();

        if (px == r-1 && py == c-1)
        {
            cout<<vist[px][py][wall];
            return 0;
        }

        for(int d=0; d<4; d++)
        {
            int nx = px + dx[d];
            int ny = py + dy[d];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

            if (wall && board[nx][ny] == '1')
            {
                q.push({{nx, ny}, 0});
                vist[nx][ny][wall-1] = vist[px][py][wall] + 1;
            }
            else if (board[nx][ny] == '0' && !vist[nx][ny][wall])
            {
                q.push({{nx, ny}, wall});
                vist[nx][ny][wall] = vist[px][py][wall] + 1;
            }
        }
    }

    cout<<"-1";
}