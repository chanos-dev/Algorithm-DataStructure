#include <bits/stdc++.h>
using namespace std;

#define y first
#define x second

int board[50][50];
bool vist[50][50];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void clear(int x, int y)
{
    for(int i=0; i<y; i++)
        for(int j=0; j<x; j++)
        {
            board[i][j] = 0;
            vist[i][j] = false;
        }
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    int t; cin>>t;

    while(t--)
    {
        int m, n, k; cin>>m>>n>>k;

        for(int i=0; i<k; i++)
        {
            int x,y; cin>>x>>y;

            board[y][x]++;
        }

        queue<pair<int,int>> q;  
        int cnt = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if (board[i][j] == 0) continue;
                if (vist[i][j]) continue;

                q.push({i,j});
                cnt++;

                while(!q.empty())
                {
                    pair<int,int> p = q.front(); q.pop();

                    for(int d=0; d<4; d++)
                    {
                        int ny = p.y + dy[d];
                        int nx = p.x + dx[d];

                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                        if (board[ny][nx] != 1) continue;

                        if (vist[ny][nx]) continue;

                        vist[ny][nx] = true;
                        q.push({ny, nx});
                    }
                } 
            }            
        }

        cout<<cnt<<"\n"; 

        clear(m, n); 
    }  
}