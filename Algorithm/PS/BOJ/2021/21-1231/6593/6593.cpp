#include<bits/stdc++.h>
using namespace std;

struct node
{
    int x;
    int y;
    int z;
    node() {}
    node(int X, int Y, int Z) : x(X), y(Y), z(Z) {}
};


int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 1, 0, -1, 0, 0};

char board[30][30][30];
int iboard[30][30][30];
bool vist[30][30][30];

int main()
{
    while(true)
    {    
        node s;
        node e;

        int l, r, c;
        cin>>l>>r>>c;

        if (l+r+c == 0)
            break;

        for(int i=0; i<l; i++)
            for(int j=0; j<r; j++)
                for(int z=0; z<c; z++)
                {
                    cin>>board[i][j][z];

                    iboard[i][j][z] = 0;
                    vist[i][j][z] = false;

                    if (board[i][j][z] == 'S')
                        s = node(i, j, z);              
                    else if (board[i][j][z] == 'E')          
                        e = node(i, j, z);
                } 

        bool isEscape = false;

        queue<node> q;
        q.push(s);
        vist[s.x][s.y][s.z] = true;
        iboard[s.x][s.y][s.z] = 1;

        while(!q.empty())
        {
            node f = q.front(); q.pop();

            for(int d=0; d<6; d++)
            {
                int nx = f.x + dx[d];
                int ny = f.y + dy[d];
                int nz = f.z + dz[d];

                if (nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >= c) continue;

                if (board[nx][ny][nz] == '#') continue;

                if (vist[nx][ny][nz]) continue; 

                iboard[nx][ny][nz] = iboard[f.x][f.y][f.z] + 1;
                vist[nx][ny][nz] = true;

                q.push({nx, ny, nz});

                if (nx == e.x && ny == e.y && nz == e.z)
                {
                    isEscape = true;
                    break;
                }
            }

            if (isEscape) break;
        }

        // for(int i=0; i<l; i++)
        // {
        //     for(int j=0; j<r; j++)
        //     {
        //         for(int z=0; z<c; z++)
        //         {
        //             cout<<iboard[i][j][z]<<" ";
        //         }
        //         cout<<"\n";
        //     }
        //     cout<<"\n\n";
        // }

        if (isEscape)
        {
            cout<<"Escaped in "<<iboard[e.x][e.y][e.z]-1<<" minute(s)."<<"\n";
        }
        else
        {
            cout<<"Trapped!\n";
        }  
    }
}