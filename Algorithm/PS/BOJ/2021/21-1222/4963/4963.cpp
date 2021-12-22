#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second


int board[51][51];
bool vist[51][51];

int dx[8] = {1,0,-1,0, -1, -1, 1, 1};
int dy[8] = {0,1,0,-1, -1, 1, -1, 1};

void clear(int x, int y)
{
    for(int i=0; i<y; i++)
    {
        for (int j=0; j<x; j++)
        {
            board[i][j] = 0;
            vist[i][j] = 0;
        }
    }
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    while(true)
    {
        int x, y; cin>>x>>y;

        if (x+y < 1)
            break; 

        for(int i=0; i<y; i++)
            for (int j=0; j<x; j++)
                cin>>board[i][j];
        
        queue<pair<int,int>> q;
        int cnt = 0;
        for(int i=0; i<y; i++)
        {
            for (int j=0; j<x; j++)
            {
                if (board[i][j] == 0) continue;

                if (vist[i][j]) continue;

                q.push({i, j});
                cnt++;

                while(!q.empty())
                { 
                    pair<int,int> p = q.front(); q.pop();

                    for(int d=0; d<8; d++)
                    {
                        int nx = p.x + dx[d];
                        int ny = p.y + dy[d];

                        if (nx < 0 || nx >= y || ny < 0 || ny >= x) continue;

                        if (board[nx][ny] != 1) continue;
                        if (vist[nx][ny]) continue;

                        vist[nx][ny] = true;
                        q.push({nx, ny});
                    } 
                }
            }
        }
        cout<<cnt<<"\n"; 

        clear(x, y);
    }
}