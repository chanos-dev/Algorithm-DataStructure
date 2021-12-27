#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

int board[300][300];

int main()
{
    int t; cin>>t;

    while(t--)
    {
        int n; cin>>n;        

        int posNx, posNy; cin>>posNx>>posNy;        
        int aposNx, aposNy; cin>>aposNx>>aposNy;

        queue<pair<int,int>> q; 

        q.push({posNx, posNy}); 
        bool isArrive = false;

        while(!q.empty())
        {
            pair<int, int> p = q.front(); q.pop();

            if (p.x == aposNx && p.y == aposNy)
            {
                cout<<board[p.x][p.y]<<"\n";
                break;
            }

            for(int d=0; d<8; d++)
            {
                int nx = p.x + dx[d];
                int ny = p.y + dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >=n) continue;
                if (board[nx][ny] != 0) continue;

                board[nx][ny] = board[p.x][p.y]+1;

                if (nx == aposNx && ny == aposNy)
                {
                    isArrive = true;
                    cout<<board[nx][ny]<<"\n";
                    break;
                }
                q.push({nx, ny}); 
            }

            if (isArrive) break;
        }

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                board[i][j] = 0;
    }
}