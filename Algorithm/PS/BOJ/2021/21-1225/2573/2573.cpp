#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[300][300];
bool vist[300][300];

int main()
{
    int r, c; cin>>r>>c;
    vector<pair<int,int>> posB;
    queue<pair<int,int>> q;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>board[i][j];

            if (board[i][j] != 0) 
            {
                posB.push_back({i, j});
                q.push({i, j});
            }
        }
    }

    int year = 0;
    
    while(true)
    {
        year++;

        while(!q.empty())
        {
            pair<int, int> p = q.front(); q.pop();

            for(int d=0; d<4; d++)
            {
                int nx = p.x + dx[d];
                int ny = p.y + dy[d];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                
                if (board[nx][ny] != 0) continue;

                board[p.x][p.y]--;

                if (board[p.x][p.y] == 0) board[p.x][p.y] = -1;
            }
        }

        // 빙산 재정리 및 확인
        int area = 0;
        for(pair<int, int> pos : posB)
        {
            if (board[pos.x][pos.y] <= -1) 
                board[pos.x][pos.y] = 0;
            else
            {
                q.push({pos.x, pos.y});
                while(!q.empty())
                {
                    pair<int, int> p = q.front(); q.pop();

                    if (board[p.x][p.y] == 0) continue;
                    if (!vist[p.x][p.y] && board[p.x][p.y] != 0)
                    { 
                        area++;         
                    }

                    for(int d=0; d<4; d++)
                    {
                        int nx = p.x + dx[d];
                        int ny = p.y + dy[d];

                        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                        
                        if (vist[nx][ny]) continue;
                        if (board[nx][ny] <= 0) continue;
                        
                        vist[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
        }

        for(pair<int, int> pos : posB)
        {
            vist[pos.x][pos.y] = false;

            if (board[pos.x][pos.y] > 0) 
                q.push({pos.x, pos.y});
        }
        
        if (area == 0)
        {
            year = 0;
            break;
        }
        
        if (area >= 2) break;
    }

    cout<<year;
}