#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void clear(int n, int m)
{
    for(int i=0; i<n; i++)
        fill_n(arr[i], m, 0);
}

void dfs(int x, int y)
{
    if (x < 0 || x > n || y < 0 || y > m) return;
    if (arr[x][y] == 0) return;
    arr[x][y] = 0;

    for(int d=0; d<4; d++)
    {
        int nx = dx[d] + x;
        int ny = dy[d] + y;
        dfs(nx, ny);
    }
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int t; cin>>t;

    while(t--)
    {
        int k; cin>>m>>n>>k;                
        clear(n, m);
        while(k--)
        {
            int x,y; cin>>x>>y;
            arr[y][x] = 1;
        }

        int cnt = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if (arr[i][j] == 1)
                {
                    dfs(i, j);
                    cnt++;
                }
            }

        cout<<cnt<<"\n";
    }
}

// #include <bits/stdc++.h>
// using namespace std;

// int arr[51][51];
// bool vist[51][51];
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};

// void clear(int n, int m)
// {
//     for(int i=0; i<n; i++)
//     {
//         fill_n(arr[i], m, 0);
//         fill_n(vist[i], m, false);
//     }
// }

// int main()
// { 
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);  

//     int t; cin>>t;

//     while(t--)
//     {
//         int n, m, k; cin>>m>>n>>k;                
//         clear(n, m);
//         while(k--)
//         {
//             int x,y; cin>>x>>y;
//             arr[y][x] = 1;
//         }

//         stack<pair<int, int>> stk;
//         int cnt = 0;
//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<m; j++)
//             {
//                 if (arr[i][j] == 0) continue;
//                 if (vist[i][j]) continue;

//                 cnt++;

//                 stk.push({i, j});
//                 vist[i][j] = true; 
//                 while(!stk.empty())
//                 {
//                     pair<int, int> p = stk.top(); stk.pop();

//                     for(int d=0; d<4; d++)
//                     {
//                         int nx = dx[d] + p.first;
//                         int ny = dy[d] + p.second;
                        
//                         if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
//                         if (arr[nx][ny] == 0 || vist[nx][ny]) continue;             
//                         vist[nx][ny] = true;  
//                         stk.push({nx, ny});
//                     }
//                 }
//             }
//         }

//         cout<<cnt<<"\n";
//     }
// }