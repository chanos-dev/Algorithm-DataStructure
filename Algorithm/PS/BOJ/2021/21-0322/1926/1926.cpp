#include <bits/stdc++.h>
using namespace std;

int board[501][501] = {0,};
bool vist[501][501] = {0,};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    int n,m;
    cin>>n>>m;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>board[i][j];
    
    int mx = 0;
    int cnt = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if (board[i][j] == 0 || vist[i][j])
                continue;
            
            cnt++;

            queue<pair<int, int>> q;

            vist[i][j] = true;

            q.push({i,j});

            int area = 0;
            while(!q.empty())
            {
                area++;
                pair<int, int> cur = q.front();
                q.pop();

                for(int l=0; l<4; l++)
                {
                    int nx = cur.first + dx[l];
                    int ny = cur.second + dy[l];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    
                    if (board[nx][ny] == 0 || vist[nx][ny])
                        continue;
                    
                    vist[nx][ny] = true;
                    q.push({nx, ny});
                }
            }

            mx = max(mx, area);
        }
    }

    cout<<cnt<<"\n"<<mx;
}