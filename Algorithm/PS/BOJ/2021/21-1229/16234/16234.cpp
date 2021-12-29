#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[50][50];
int state[50][50];
vector<pair<int, int>> vec[2000];

int main()
{
    int n, L, R; cin>>n>>L>>R;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>board[i][j];

    queue<pair<int, int>> q;

    int cnt = 0;
    
    while(true)
    {
        int group = 1; 

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                q.push({i, j});

                while(!q.empty())
                {
                    pair<int, int> p = q.front(); q.pop(); 
 

                    for(int d=0; d<4; d++)
                    {
                        int nx = p.x + dx[d];
                        int ny = p.y + dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (state[nx][ny] != 0 ) continue;

                        int diff = abs(board[p.x][p.y] - board[nx][ny]);
                        
                        if (L <= diff && diff <= R)
                        {   
                            if (state[p.x][p.y] == 0)
                            {
                                state[p.x][p.y] = group;
                                state[nx][ny] = group;

                                vec[group].push_back({p.x, p.y});
                                vec[group].push_back({nx, ny});

                                group++;
                            }
                            else
                            {
                                state[nx][ny] = state[p.x][p.y];

                                vec[state[p.x][p.y]].push_back({nx, ny});
                            } 

                            q.push({nx, ny});  
                        }
                    }
                }  
            }
        }   

        bool isend = true;

        for(int i = 0; i<group; i++)
        {
            if (!vec[i].empty()) 
            {
                isend = false;
                int sum = 0;

                for(pair<int, int> p : vec[i])
                {
                    sum += board[p.x][p.y];
                    state[p.x][p.y] = 0;  
                }

                for(pair<int, int> p : vec[i])
                {
                    board[p.x][p.y] = sum / vec[i].size();
                }
                
                vec[i].clear(); 
            }
        } 

        if (isend) break;  

        cnt++; 
    } 

    cout<<cnt;
}