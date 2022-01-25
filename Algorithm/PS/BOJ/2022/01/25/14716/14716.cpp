#include<bits/stdc++.h>
using namespace std;

int board[251][251];
bool vist[251][251];

int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1}; 

int main()
{
    int m, n; cin>>m>>n;

    vector<pair<int, int>> pos;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>board[i][j];

            if(board[i][j]) pos.push_back({i, j});
        }
    }

    queue<pair<int, int>> q;
    int ans = 0;
    for(pair<int, int> p : pos)
    {
        if (vist[p.first][p.second]) continue;

        q.push(p);
        ans++;

        while(!q.empty())
        {            
            pair<int, int> c = q.front(); q.pop();

            for(int d=0; d<8; d++)
            {
                int nx = c.first + dx[d];
                int ny = c.second + dy[d];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (board[nx][ny] != 1) continue;
                if (vist[nx][ny]) continue;

                vist[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }

    cout<<ans;
}