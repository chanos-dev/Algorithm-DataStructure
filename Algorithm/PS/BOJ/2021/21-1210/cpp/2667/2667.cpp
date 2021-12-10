#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

char input[25][25];
int board[25][25] = { 0, };
bool vist[25][25];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; cin>>n;
    
    for(int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin>>input[i][j]; 

    for(int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            board[i][j] = input[i][j] - '0';  

    vector<int> t;

    for(int i=0; i<n; i++)
    {
        queue<pair<int, int>> q;
        int cnt = 0;

        for (int j=0; j<n; j++)
        {  
            if (vist[i][j])
                continue;

            if (board[i][j] == 1)
            {
                q.push({i, j});
                vist[i][j] = true;
                cnt++;
            }
            
            while(!q.empty())
            {
                pair<int, int> c = q.front();
                q.pop();

                for(int d=0; d<4; d++)
                {
                    int nx = c.x + dx[d];
                    int ny = c.y + dy[d];

                    if (nx < 0 || nx >= n || 
                        ny < 0 || ny >= n)
                        continue;
                    
                    if (vist[nx][ny] || board[nx][ny] != 1)
                        continue;
                    
                    // 방문표시
                    vist[nx][ny] = true;
                    q.push({nx, ny});
                    cnt++;
                }
            } 

            if (cnt != 0)
            {
                t.push_back(cnt);
                cnt = 0;                   
            }
        } 
    }

    cout<<t.size()<<"\n";

    sort(t.begin(), t.end());
    for(int i : t)
        cout<<i<<"\n";
}