#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second 

vector<pair<int, int>> chicken, sc;
vector<pair<int, int>> house;

int board[51][51]; 
bool mychicken[13];

int ans = 9999999;
int n, m;

void find(int i, int k)
{
    if (k == m)
    {        
        int sum = 0;
        for(pair<int, int> h : house)
        {
            int minv = 9999999;
            int r1 = h.x;
            int c1 = h.y;

            for(pair<int, int> s : sc)
            {
                int r2 = s.x;
                int c2 = s.y;

                int dist = abs(r1-r2) + abs(c1-c2);

                minv = min(dist,minv);
            }
            
            sum += minv;
        } 

        ans = min(ans, sum);        
        return;
    }

    for(int ii=i; ii<chicken.size(); ii++)
    {
        if (mychicken[ii]) continue;
        mychicken[ii] = true;
        sc.push_back(chicken[ii]);
        find(ii, k+1);
        sc.pop_back();
        mychicken[ii] = false;
    } 
}

int main()
{
    cin>>n>>m;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            cin>>board[i][j];
            if (board[i][j] == 2)
                chicken.push_back({i, j});
            if (board[i][j] == 1)
                house.push_back({i, j});
        }
        
    find(0, 0);
    cout<<ans;
}