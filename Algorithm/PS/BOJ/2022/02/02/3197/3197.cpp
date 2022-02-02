#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dx[] = {1, 0, -1 ,0};
int dy[] = {0, 1, 0, -1};

char board[1501][1501];
bool vist[1501][1501];

pair<int, int> pos[2];
queue<pair<int, int>> ground;
queue<pair<int, int>> point;
int r, c; 
int idx = 0;

bool Out(int i, int j)
{
    return i < 0 || i >= r || j < 0 || j >= c;
}

void Remove()
{
    queue<pair<int, int>> next;

    while(!ground.empty())
    {
        pair<int, int> p = ground.front();
        ground.pop(); 

        for(int d=0; d<4; d++)
        {
            int nx = p.x + dx[d];
            int ny = p.y + dy[d];

            if (Out(nx, ny)) continue;

            if (board[nx][ny] == 'X')
            {
                board[nx][ny] = '.';
                next.push({nx, ny});
            } 
        }
    } 

    ground = next;
}

bool Find()
{ 
    queue<pair<int, int>> ice;
    while(!point.empty())
    {
        pair<int, int> p = point.front(); point.pop();

        if (p.x == pos[1].x && p.y == pos[1].y)
            return true;

        for(int d=0; d<4; d++)
        {
            int nx = p.x + dx[d];
            int ny = p.y + dy[d];

            if (Out(nx, ny)) continue; 
            if (vist[nx][ny]) continue;
            vist[nx][ny] = true;

            if (board[nx][ny] == 'X') 
            {
                ice.push({nx, ny});
                continue;
            }

            point.push({nx, ny});
        }
    }

    point = ice;
    return false;
}  

int main()
{     
    cin>>r>>c; 

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
        {
            cin>>board[i][j];
            if (board[i][j] == 'L')
                pos[idx++] = {i, j};
            if (board[i][j] != 'X')
                ground.push({i, j});
        }
    
    int ans;
    point.push(pos[0]);
    vist[pos[0].x][pos[0].y] = true;

    while(true)
    {
        Remove();
        ans++;
        if (Find())
            break;
    } 

    cout<<ans;
}