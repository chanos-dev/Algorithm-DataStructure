#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char board[50][50];
int water[50][50];
int go[50][50];

int main()
{
    queue<pair<int,int>> q;
    vector<pair<int, int>> posW;
    pair<int, int> posG;
    pair<int, int> posE;

    int r, c; cin>>r>>c;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>board[i][j];

            if (board[i][j] == 'D')
                posE = {i, j};
            else if (board[i][j] == '*')
                posW.push_back({i, j});
            else if (board[i][j] == 'S')
                posG = {i, j};
        }
    }

    for(pair<int,int> p : posW)
    {
        q.push(p);
        water[p.x][p.y] = 1;
    } 

    while(!q.empty())
    {
        pair<int, int> p = q.front(); q.pop();

        for(int d=0; d<4; d++)
        {
            int nx = p.x + dx[d];
            int ny = p.y + dy[d];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

            if (board[nx][ny] == 'X' || board[nx][ny] == 'D') continue;

            if (water[nx][ny] != 0) continue;

            water[nx][ny] = water[p.x][p.y]+1;
            q.push({nx,ny});
        }
    }

    q.push(posG);
    go[posG.x][posG.y] = 1;

    while(!q.empty())
    {
        pair<int,int> p = q.front(); q.pop();

        for(int d=0; d<4; d++)
        {
            int nx = p.x + dx[d];
            int ny = p.y + dy[d];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

            if (board[nx][ny] == 'X') continue;

            if (go[nx][ny] != 0) continue;

            if (water[nx][ny] <= go[p.x][p.y]+1 && water[nx][ny] != 0) continue;

            if (nx == posE.x && ny == posE.y)
            {
                cout<<go[p.x][p.y];
                return 0;
            }

            go[nx][ny] = go[p.x][p.y]+1;
            q.push({nx, ny});
        }
    }

    cout<<"KAKTUS";
    // for(int i=0; i<r; i++)
    // {
    //     for(int j=0; j<c; j++)
    //     {
    //         cout<<water[i][j] <<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";
    // for(int i=0; i<r; i++)
    // {
    //     for(int j=0; j<c; j++)
    //     {
    //         cout<<go[i][j] <<" ";
    //     }
    //     cout<<"\n";
    // }
}