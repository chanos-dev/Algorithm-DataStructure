#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

char board[50][50];
vector<pair<int, int>> posL;
int r, c;

int main()
{
    cin>>r>>c;

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
        {
            cin>>board[i][j];
            if(board[i][j] == 'L')
                posL.push_back({i, j});
        }

    int max = -1;

    for(pair<int, int> p : posL)
    {
        queue<pair<int, int>> q;
        q.push(p);

        int vist[r][c];
        for(int i=0; i<r; i++)
            fill_n(vist[i], c, 0);

        vist[p.x][p.y] = 1;

        while(!q.empty())
        {
            pair<int, int> cur = q.front(); q.pop();

            for(int d=0; d<4; d++)
            {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (board[nx][ny] == 'W') continue;
                if (vist[nx][ny] != 0) continue;

                vist[nx][ny] = vist[cur.x][cur.y]+1;
                if (max < vist[nx][ny])
                    max = vist[nx][ny];
                q.push({nx, ny});
            }
        } 
    }

    cout<<max-1;
}
