#include <bits/stdc++.h>
using namespace std;

string board[101];
bool vist[101][101] = {0,};
int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(bool RG)
{
    if (RG)
    {
        for(int i=0; i<N; i++) 
            for(int j=0; j<N; j++) 
                if (board[i][j] == 'G')
                    board[i][j] = 'R';  
    }

    int color = 0;

    char curColor;         

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {            
            if(vist[i][j] == 1) continue;            
             
            curColor = board[i][j]; 
            
            color++;

            queue<pair<int, int>> q;

            vist[i][j] = true;

            q.push({i,j});

            while(!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();

                for(int l=0; l<4; l++)
                {
                    int nx = cur.first + dx[l];
                    int ny = cur.second + dy[l];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                    if (vist[nx][ny] == 1 || board[nx][ny] != curColor) continue;

                    vist[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    cout<<color<<" ";
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);   

    cin>>N;

    for(int i=0; i<N; i++)
        cin>>board[i]; 

    BFS(false);

    //clear visit 
    for(int i=0; i<N; i++)
        fill(vist[i], vist[i]+N, 0);
    
    BFS(true);
}