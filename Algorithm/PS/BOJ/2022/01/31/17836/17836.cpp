#include<bits/stdc++.h>
using namespace std;

int board[101][101];
int vist[101][101][101];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    int n, m, t; cin>>n>>m>>t;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cin>>board[i][j];
            if (board[i][j] == 2) board[i][j] = -1;
        }
    
    queue<pair<pair<int, int>, int>> q;
    vist[0][0][0] = 2;
    q.push({{0, 0}, 0});

    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int w = q.front().second;
        q.pop();
        if (x == n-1 && y == m-1)
        {
            cout<<vist[x][y][w]-2;
            return 0;
        } 

        for(int d=0; d<4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (w > 100) continue;
            else
            {
                if (vist[nx][ny][w] > t+2)
                {
                    cout<<"Fail";
                    return 0;
                }
            } 

            if (board[nx][ny] == -1 || (w > 0 && vist[nx][ny][w+1] == 0 && board[nx][ny] == 1))
            {
                if (board[nx][ny] == -1) board[nx][ny] = vist[x][y][w]+1;

                vist[nx][ny][w+1] = vist[x][y][w]+1;
                q.push({{nx, ny}, w+1});
            } 

            if (vist[nx][ny][w] == 0 && board[nx][ny] != 1)
            { 
                vist[nx][ny][w] = vist[x][y][w]+1;
                q.push({{nx, ny}, w});
            } 
        } 
    } 

    cout<<"Fail";
}