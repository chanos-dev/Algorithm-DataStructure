#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

int ans = 9999999;
int n, m;
char board[21][21];
pair<int, int> pos[2];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0}; 

int drop(pair<int, int> pm[])
{
    int o = 0;
    for(int i=0; i<2; i++)
    {
        if (pm[i].x < 0 || pm[i].x >= n || pm[i].y < 0 || pm[i].y >= m)
            o++;
    }

    return o;
} 

void move(pair<int, int> pm[], int d, int k)
{    
    if (k > 10) return;
    if (k > ans) return; 

    pair<int, int> pt[2];

    for(int i=0; i<2; i++)
    {
        pt[i] = {pm[i].x + dx[d], pm[i].y + dy[d]};
    }

    if (drop(pt) == 2) return;
    else if (drop(pt) == 1)
    {
        if (k < ans)
        {
            ans = k;
        }
        return;
    }

    for(int i=0; i<2; i++)
    {
        if (board[pt[i].x][pt[i].y] == '#')
        {
            pt[i] = pm[i];
        }
    }

    if (pt[0] == pt[1])
        return;

    for(int d=0; d<4; d++)
    {
        move(pt, d, k+1);
    }
} 

void sol()
{
    for(int d=0; d<4; d++)
    {
        move(pos, d, 1);
    }
}

int main()
{
    int idx = 0;
    cin>>n>>m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cin>>board[i][j];
            if (board[i][j] == 'o')
                pos[idx++] = {i, j};
        }

    sol();

    if (ans > 10) cout<<"-1";
    else cout<<ans;
}