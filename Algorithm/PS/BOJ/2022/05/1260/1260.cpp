#include <bits/stdc++.h>
using namespace std;

int n;
set<int> node[1'001];
bool vist[1'001];

void dfs(int s)
{
     for(int n : node[s])
     {
         if (vist[n]) continue;
         vist[n] = true;
         cout<<n<<" ";
         dfs(n);
     }
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);    
    while(!q.empty())
    {
        int p = q.front(); q.pop();

        for(int n : node[p])
        {
            if (vist[n]) continue;
            vist[n] = true;
            cout<<n<<" ";
            q.push(n);
        }
    }
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int m, v; cin>>n>>m>>v;

    for(int i=0; i<m; i++)
    {
        int a, b; cin>>a>>b;
        node[a].insert(b);
        node[b].insert(a);
    }

    cout<<v<<" ";
    vist[v] = true;
    dfs(v);    
    cout<<"\n";
    fill_n(vist, n+1, false);
    cout<<v<<" ";
    vist[v] = true;
    bfs(v);
}