#include<bits/stdc++.h>
using namespace std;

int board[201][201];
bool vist[201][201];

int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};

int main()
{
    int n; cin>>n;

    int r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2;

    queue<pair<pair<int, int>, int>> q;
    q.push({{r1, c1}, 0});

    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int k = q.front().second;
        q.pop();

        if (x == r2 && y == c2)
        {
            cout<<k;
            return 0;
        }
    
        for(int d=0; d<6; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vist[nx][ny]) continue;

            vist[nx][ny] = true;
            q.push({{nx, ny}, k+1});
        }
    }

    cout<<"-1";
}