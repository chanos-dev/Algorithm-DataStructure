#include<bits/stdc++.h>
using namespace std;

struct tomato
{
    int x;
    int y;
    int z;
    tomato() {}
    tomato(int X, int Y, int Z) : x(X), y(Y), z(Z){}
};

int board[100][100][100];

int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {1, 0, -1, 0, 0, 0};
int dz[] = {0, 1, 0, -1, 0, 0};

int main()
{
    int m, n, h; cin>>m>>n>>h;
    queue<tomato> q;
    int ze = 0;

    for(int i=0; i<h; i++)
        for(int j=0; j<n; j++)
            for(int z=0; z<m; z++)
            {
                cin>>board[i][j][z];
                
                if (board[i][j][z] == 1)
                    q.push(tomato(i, j, z));
                if (board[i][j][z] == 0)
                    ze++;
            } 

    if (ze == 0)
    {
        cout<<"0";
        return 0;
    }
    
    int day = 0;

    while(!q.empty())
    {
        tomato t = q.front(); q.pop();

        for(int d=0; d<6; d++)
        {
            int nx = t.x + dx[d];
            int ny = t.y + dy[d];
            int nz = t.z + dz[d];

            if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;

            if (board[nx][ny][nz] != 0) continue;

            board[nx][ny][nz] = board[t.x][t.y][t.z] + 1;
            if (board[nx][ny][nz] > day)
                day = board[nx][ny][nz];
            q.push({nx, ny, nz});
        }
    }

    bool isall = true;

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int z=0; z<m; z++)
            {
                if (board[i][j][z] == 0)
                { 
                    isall = false;
                    break;
                }
            }
            if (!isall) break;
        }
        if (!isall) break;
    }

    if (isall) cout<<day-1;
    else cout<<"-1";

    // for(int i=0; i<h; i++)
    // {
    //     for(int j=0; j<n; j++)
    //     {
    //         for(int z=0; z<m; z++)
    //         {
    //             cout<<board[i][j][z]<<" ";
    //         }
    //         cout<<"\n";
    //     }
    //     cout<<"\n\n";
    // }
}