#include<bits/stdc++.h>
using namespace std;

vector<int> f[501];
bool vist[501];
queue<pair<int, int>> q;
int ans = 0; 

int main()
{
    int n, m; cin>>n>>m;
    vector<int> root;

    for(int i=0; i<m; i++)
    {
        int a, b; cin>>a>>b; 

        f[a].push_back(b);
        f[b].push_back(a); 
    }

    q.push({1, 0});
    vist[1] = true;
    while(!q.empty())
    {
        int i = q.front().first;
        int d = q.front().second;
        q.pop();

        if (d > 1) continue; 

        for(int c : f[i])
        {         
            if (vist[c]) continue;
            vist[c] = true;

            q.push({c, d+1});
            ans++;
        } 
    }

    cout<<ans;
}