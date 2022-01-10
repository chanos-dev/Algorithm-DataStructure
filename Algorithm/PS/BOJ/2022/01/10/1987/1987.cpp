#include<bits/stdc++.h>
using namespace std;

char board[20][20];
int ans = 0;
bool used[27];

int r, c;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void alpha(int i, int j, int k)
{    
    for(int d=0; d<4; d++)
    {
        int nx = i + dx[d];
        int ny = j + dy[d];

        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if (used[board[nx][ny]-'A']) continue;

        used[board[nx][ny]-'A']  = true;
        alpha(nx, ny, k+1);
        used[board[nx][ny]-'A']  = false;
    }

    if (ans < k)
        ans = k;
}

int main()
{
    cin>>r>>c;

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin>>board[i][j];
        
    used[board[0][0]-'A'] = true;
    alpha(0, 0, 0);
    cout<<ans+1;
}