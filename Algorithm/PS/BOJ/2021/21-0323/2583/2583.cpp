#include <bits/stdc++.h>
using namespace std;

int board[101][101];
bool vist[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int M, N, K;

    cin>>M>>N>>K;


    // draw rect
    for(int i=0; i<K; i++)
    {
        int x;
        int y;
        int x2;
        int y2;

        cin>>x>>y>>x2>>y2; 
 
        for(int ii=y; ii <= y2-1; ii++)
        {
            for(int jj=x; jj <= x2-1; jj++)
            {
                board[ii][jj] = 1;
            }
        }
    }

    int cnt = 0;
    list<int> size;    
    
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {            
            if(vist[i][j] == 1 || board[i][j] == 1) continue;
            cnt++;
            queue<pair<int,int>> q;
            q.push({i,j});
            vist[i][j] = true;
            int area = 0;

            while(!q.empty())
            {
                pair<int,int> cur = q.front();
                q.pop();

                area++;

                for(int l=0; l<4; l++)
                {
                    int nx = cur.first + dx[l];
                    int ny = cur.second + dy[l];

                    if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

                    if(vist[nx][ny] == 1 || board[nx][ny] == 1) continue;

                    q.push({nx,ny});
                    vist[nx][ny] = true;
                }
            }

            size.push_back(area);
        }
    }

    cout<<cnt<<"\n";

    size.sort();

    for(auto e : size) 
        cout<<e<<" "; 
}