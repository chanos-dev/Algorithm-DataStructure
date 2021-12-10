#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int ground[100][100];
bool vist[100][100];
 
int main()
{
    int n; cin>>n;

    int rMax = -1;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>ground[i][j];

            if (ground[i][j] > rMax)
                rMax = ground[i][j];
        }
    } 

    queue<pair<int,int>> q;
    int gMax = 0;

    for(int r=0; r<=rMax; r++)
    {
        int g = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if (vist[i][j]) continue;

                if (ground[i][j] <= r) continue;

                q.push({i, j});
                vist[i][j] = true;
                g++;

                while(!q.empty())
                {
                    pair<int,int> p = q.front(); q.pop();

                    for(int d=0; d<4; d++)
                    {
                        int nx = p.x + dx[d];
                        int ny = p.y + dy[d];

                        if (nx < 0 || nx >= n ||
                            ny < 0 || ny >= n)
                            continue;
                        
                        if (vist[nx][ny] || ground[nx][ny] <= r) continue;

                        vist[nx][ny] = true;
                        q.push({nx,ny});                        
                    }
                }
            }
        }

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                vist[i][j] = false;

        gMax = max(gMax, g);
    } 

    cout<<gMax;
}