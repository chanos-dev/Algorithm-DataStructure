#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[100][100] = {0, };
bool vist[100][100] = {0, };

int main()
{
    int n; cin>>n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>board[i][j];
        }
    }

    queue<pair<int,int>> gq;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if (vist[i][j] || board[i][j] == 0) continue;

            queue<pair<int,int>> q;
            q.push({i,j});

            gq.push({101,101});
            gq.push({i,j});
            vist[i][j] = true;

            while(!q.empty())
            {
                pair<int,int> p = q.front(); q.pop();

                for(int d=0; d<4; d++)
                {
                    int nx = p.x + dx[d];
                    int ny = p.y + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                    if (board[nx][ny] == 0 || vist[nx][ny]) continue;

                    vist[nx][ny] = true;
                    q.push({nx, ny});
                    gq.push({nx, ny});
                }
            }


        }
    }  

    vector<int> v;
    while(!gq.empty())
    { 
        int checkboard[100][100] = {0,}; 

        if (gq.front().x == 101  && gq.front().y == 101)
        { 
            gq.pop();
            
            queue<pair<int, int>> q;            

            while(!gq.empty() && gq.front().x != 101 && gq.front().y != 101)
            {
                pair<int,int> p = gq.front(); 
                gq.pop();

                checkboard[p.x][p.y] = 1;                
                q.push({p.x, p.y});                
            }

            bool ar = false;

            while(!q.empty())
            {
                pair<int,int> p = q.front(); q.pop();

                for(int d=0; d<4; d++)
                {
                    int nx = p.x + dx[d];
                    int ny = p.y + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                    if (checkboard[nx][ny] != 0) continue;                    

                    checkboard[nx][ny] = checkboard[p.x][p.y] + 1;

                    // 도착한 영역이 다른 섬이면
                    if (board[nx][ny] == 1)
                    {                 
                        ar = true;       
                        v.push_back(checkboard[nx][ny]);
                        break;
                    }

                    q.push({nx,ny});
                }

                if (ar)  break;
            }  
        } 
    }  

    sort(v.begin(), v.end());

    cout<<v[0]-2;
}