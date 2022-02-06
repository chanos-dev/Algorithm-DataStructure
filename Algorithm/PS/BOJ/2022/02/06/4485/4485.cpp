#include<bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int board[126][126];
int cost[126][126];

bool out(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= n;
}

void zelda(int i, int j)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{i, j}, board[i][j]});
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int pk = q.front().second;
        q.pop(); 

        for(int d=0; d<4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (out(nx,ny)) continue;
            if (cost[nx][ny] <= pk + board[nx][ny]) continue;

            cost[nx][ny] = pk + board[nx][ny];            
            if (nx == n-1 && ny == n-1)
                continue;

            q.push({{nx, ny}, cost[nx][ny]});                        
        } 
    }
} 

int main()
{
    int t = 0;
    while(true)
    {        
        cin>>n;
        t++; 
        if(n == 0) break;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                cin>>board[i][j];
                cost[i][j] = 200000;
            }

        zelda(0, 0);

        cout<<"Problem "<<t<<": "<<cost[n-1][n-1]<<"\n";
    }
}