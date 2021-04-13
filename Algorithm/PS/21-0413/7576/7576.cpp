#include <bits/stdc++.h>
using namespace std; 

int board[1001][1001];
int M,N;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    int M,N;
    bool isZero = false;
    queue<pair<int,int>> q; 

    cin>>M>>N;     

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
        {
            cin>>board[i][j];

            if(board[i][j] == 1) 
                q.push({i, j}); 
            else if(board[i][j] == 0) isZero = true;
        }

    if (!isZero)
    {
        cout<<"0";
        return 0;
    }
    
    int day = 0;  

    while(!q.empty())
    {  
        pair<int, int> cur = q.front();
        q.pop();

        for(int l=0; l<4; l++)
        {
            int nx = cur.first + dx[l];
            int ny = cur.second + dy[l]; 

            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;

            if(board[nx][ny] >= 1 || board[nx][ny] < 0) continue;

            board[nx][ny] = board[cur.first][cur.second]+1; 

            q.push({nx,ny});

            day = max(day, board[nx][ny]);
        }
    }
    
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) 
            if(board[i][j] == 0)
            {
                cout<<"-1";
                return 0;
            } 
     
    cout<<day-1; 
}