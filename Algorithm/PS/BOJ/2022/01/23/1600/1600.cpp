#include<bits/stdc++.h>
using namespace std;

int board[201][201];
int vist[201][201][31];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int hdx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int hdy[] = {-2, -1, 1, 2, -2, -1, 1, 2};

int main()
{
    int k; cin>>k;
    int w,h; cin>>w>>h;

    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
        {
            cin>>board[i][j];
        }

    queue<pair<pair<int, int>,int>> q;
    board[0][0] = 2;
    vist[0][0][k] = 2;
    q.push({{0, 0}, k});

    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int j = q.front().second;
        q.pop();

        if (x == h-1 && y == w-1)
        {
            cout<<vist[x][y][j]-2;
            return 0;
        }

        for(int d=0; d<4; d++)
        {
            int nx = dx[d] + x;
            int ny = dy[d] + y;

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;  
            if (board[nx][ny] == 0 && vist[nx][ny][j] == 0)
            {
                vist[nx][ny][j] = vist[x][y][j] + 1;
                q.push({{nx, ny}, j});
            }
        } 

        if (j > 0)
        {
            for(int m=0; m<8; m++)
            {
                int mnx = hdx[m] + x;
                int mny = hdy[m] + y;

                if (mnx < 0 || mnx >= h || mny < 0 || mny >= w) continue;
                
                if (board[mnx][mny] == 0 && vist[mnx][mny][j-1] == 0)
                {
                    vist[mnx][mny][j-1] = vist[x][y][j] + 1;
                    q.push({{mnx, mny}, j-1});        
                }
            }
        }
    }

    cout<<"-1";
}