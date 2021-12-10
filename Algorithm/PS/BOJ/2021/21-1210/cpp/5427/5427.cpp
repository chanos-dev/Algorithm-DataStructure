#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

char board[1000][1000];
int fire[1000][1000];
int person[1000][1000];

int main()
{
    int n; cin>>n;

    vector<string> ans;

    for(int i=0; i<n; i++)
    { 
        int r, c; cin>>r>>c;

        queue<pair<int,int>> q;
        vector<pair<int, int>> posF;
        pair<int, int> posJ;

        bool isF = false;

        for(int i=0; i<c; i++)
        {
            for(int j=0; j<r; j++)
            {
                cin>>board[i][j];

                if (board[i][j] == '*')
                    posF.push_back({i, j});
                else if (board[i][j] == '@')
                    posJ = {i, j};
            }        
        }  

        for(pair<int,int> p : posF)
        {
            q.push(p);
            fire[p.x][p.y] = 1;
        } 

        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            
            for(int d=0; d<4; d++)
            {
                int nx = p.x + dx[d];
                int ny = p.y + dy[d]; 

                if (nx < 0 || nx >= c ||
                    ny < 0 || ny >= r)
                    continue;

                if (board[nx][ny] == '#')
                    continue;

                if (fire[nx][ny] != 0)
                    continue;
                
                fire[nx][ny] = fire[p.x][p.y] + 1;
                q.push({nx, ny});
            } 
        }

        q.push(posJ); 
        person[posJ.x][posJ.y] = 1;
        
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();

            for(int d=0; d<4; d++)
            {
                int nx = p.x + dx[d];
                int ny = p.y + dy[d];

                if (nx < 0 || nx >= c ||
                    ny < 0 || ny >= r)
                    continue;
                
                if (person[nx][ny] != 0)
                    continue;

                if (board[nx][ny] == '#')
                    continue;
                
                if (fire[nx][ny] <= person[p.x][p.y]+1 && fire[nx][ny] != 0) 
                    continue; 
                
                person[nx][ny] = person[p.x][p.y]+1;
                q.push({nx,ny});
            }
        } 

        vector<int> v;

        for(int i=0; i<c; i++)
        {
            for(int j=0; j<r; j++)
            {
                if (i == 0 || i == c-1 || j == 0 || j == r-1)
                    if (person[i][j] != 0)
                        v.push_back(person[i][j]);
            }
        }

        if (v.size() > 0)
        {
            sort(v.begin(), v.end()); 
            ans.push_back(to_string(v[0]));
        }
        else
            ans.push_back("IMPOSSIBLE");

        for(int i=0; i<c; i++)
            for(int j=0; j<r; j++)
            {
                fire[i][j] = 0;
                person[i][j] = 0;
            }
    } 

    for(string s : ans)
        cout<<s<<"\n";
}