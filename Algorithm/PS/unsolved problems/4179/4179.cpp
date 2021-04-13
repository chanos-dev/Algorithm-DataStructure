#include <bits/stdc++.h>
using namespace std;

char board[1001][1001];

int r,c;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

list<pair<int, int>> curJ;

int main()
{   
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    queue<pair<int,int>> q;

    cin>>r>>c;    

    bool isBorder = false;

    for (int i=0; i<c; i++)
    {
        for (int j=0; j<r; j++)
        {
            cin>>board[i][j];

            if (board[i][j] == 'F')                        
                q.push({i, j});

            if (board[i][j] == 'J') 
            {
                if (i == 0 || j == 0 || i == c-1 || j == r-1)
                    isBorder = true;

                board[i][j] = 49;                
                curJ.push_back({i, j});
            }
        }
    } 

    if (isBorder)
    {
        cout<<"1";
        return 0;
    }

    q.push(curJ.front());

    int dec = 0;    

    while (!q.empty())
    {        
        pair<int, int> cur = q.front();
        q.pop();
        
        bool isJcur = false;        
        bool isDec = false;

        list<pair<int,int>>::iterator it = find(curJ.begin(), curJ.end(), cur);

        if (it != curJ.end())
            isJcur = true; 

        curJ.remove(cur);

        for (int l=0; l<4; l++)
        {
            int nx = cur.first + dx[l];
            int ny = cur.second + dy[l];  

            if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;

            if (board[nx][ny] == '#' || board[nx][ny] == 'F' || board[nx][ny] == 'J' || board[nx][ny] >= '0') continue;            

            if (isJcur)
            {
                board[nx][ny] = board[cur.first][cur.second]+1;

                if (board[nx][ny] == ':') 
                { 
                    board[nx][ny] = '0';
                    isDec = true;
                }

                curJ.push_back({nx, ny});
            }
            else
                board[nx][ny] = 'F';

            q.push({nx,ny});
        }

        if (isDec) dec++;              
    }


    bool isEscape = false;
    char escapeNum = '9';

    for (int i=0; i<c; i++)
    { 
        if (i == 0 || i == c-1)
        {
            for (int j=0; j<r; j++)
            {
                if (board[i][j] >= '0' && board[i][j] <= '9') 
                {
                    isEscape = true;

                    if (escapeNum >= board[i][j])
                        escapeNum = board[i][j]; 
                }
            }
        }
        else
        {
            if (board[i][0] >= '0' && board[i][0] <= '9') 
            {
                isEscape = true;
                if (escapeNum >= board[i][0])
                    escapeNum = board[i][0]; 
            }

            if (board[i][r-1] >= '0' && board[i][r-1] <= '9') 
            {
                isEscape = true; 
                if (escapeNum >= board[i][r-1])
                        escapeNum = board[i][r-1]; 
            } 
        }             
    }

    if (!isEscape)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }   

    cout<<((int)escapeNum - 48) + (dec * 10);
} 