#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int rain[101][101];
bool vist[101][101];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0 ,-1};

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; cin>>n;

    int maxh = -1;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            cin>>rain[i][j];

            maxh = max(rain[i][j], maxh);
        }
    

    int maxS = 0;

    for(int h=0; h<maxh; h++)
    { 
        int s = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            { 
                if (vist[i][j] || rain[i][j] <= h) continue;

                queue<pair<int, int>> q;
                q.push({i, j});
                s++;

                while(!q.empty())
                {
                    pair<int, int> p = q.front(); q.pop();

                    for(int d=0; d<4; d++)
                    {
                        int nx = p.x + dx[d];
                        int ny = p.y + dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (vist[nx][ny] || rain[nx][ny] <= h) continue;

                        vist[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                vist[i][j] = false;
        
        maxS = max(s, maxS);
    }

    cout<<maxS;
}