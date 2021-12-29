#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[1000][1000];
int vist[1000][1000];

int main()
{
    int n,m; cin>>n>>m;

    pair<int, int> posA;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cin>>board[i][j];

            if (board[i][j] == 2) posA = {i, j};
        }

    queue<pair<int, int>> q;

    q.push(posA);    

    while(!q.empty())
    {
        pair<int, int> p = q.front(); q.pop();

        for(int d=0; d<4; d++)
        {
            int nx = p.x + dx[d];
            int ny = p.y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (nx == posA.x && ny == posA.y) continue;
            if (board[nx][ny] == 0) continue;
            if (vist[nx][ny] != 0) continue;

            vist[nx][ny] = vist[p.x][p.y] + 1;
            q.push({nx, ny});
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if (board[i][j] == 1 && vist[i][j] == 0)
                cout<<"-1"<<" ";
            else 
                cout<<vist[i][j]<<" ";
        }
        cout<<"\n";
    }
}