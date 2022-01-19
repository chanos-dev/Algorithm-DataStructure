#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

struct room
{
    int x;
    int y;
    int r;
    room(){}
    room(int X, int Y, int R) : x(X), y(Y), r(R) {}
};

int board[51][51];
int vist[51][51][51];
vector<int> ans;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    int n; cin>>n;    

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            char c; cin>>c;
            board[i][j] = c - '0';
        }
    
    queue<room> q;
    q.push(room(0, 0, 0));

    while(!q.empty())
    {
        room rm = q.front(); q.pop();

        for(int d=0; d<4; d++)
        {
            int nx = dx[d] + rm.x;
            int ny = dy[d] + rm.y;                        

            if (nx == n-1 && ny == n-1)
            {
                ans.push_back(rm.r);
                break;
            } 

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; 
            if (rm.r > 50) continue;

            if (board[nx][ny] == 0 && vist[nx][ny][rm.r+1] == 0)
            {                
                vist[nx][ny][rm.r+1] = vist[rm.x][rm.y][rm.r]+1;
                q.push(room(nx, ny, rm.r+1));
            }
            else if (board[nx][ny] == 1 && vist[nx][ny][rm.r] == 0)
            {
                vist[nx][ny][rm.r] = vist[rm.x][rm.y][rm.r]+1;
                q.push(room(nx, ny, rm.r));
            } 
        }
    }

    sort(ans.begin(), ans.end());
    cout<<ans[0];
}