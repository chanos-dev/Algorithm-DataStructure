#include <bits/stdc++.h>
using namespace std;

string board[101];
int dist[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; 

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n, m;

    cin>>n>>m;

    for(int i=0; i<n; i++)
        cin >> board[i];
    
    for(int i=0; i<n; i++)
        fill(dist[i], dist[i]+m, -1);
    
    queue<pair<int,int>> q;

    q.push({0, 0});
    dist[0][0] = 0;

    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for(int l=0; l<4; l++)
        {            
            int nx = cur.first + dx[l];
            int ny = cur.second + dy[l]; 

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1')
                continue;
            
            dist[nx][ny] = dist[cur.first][cur.second]+1;
            q.push({nx,ny});
        }
    }

    cout<<dist[n-1][m-1]+1;
}