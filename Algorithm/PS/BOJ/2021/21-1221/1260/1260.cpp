#include <bits/stdc++.h>
using namespace std;

vector<int> node[1001]; 
bool vist[1001];

queue<int> stk; 

void dfs(int i)
{ 
    for(int n : node[i])
    {
        if (vist[n]) continue;

        vist[n] = true;
        cout<<n<<" ";
        dfs(n);
    }
}

void bfs(int i)
{
    stk.push(i);

    while(!stk.empty())
    {
        int n = stk.front(); stk.pop(); 

        for(int l : node[n])
        {
            if (vist[l]) continue;
            vist[l] = true;

            cout<<l<<" ";
            stk.push(l);
        }
    }
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, v; cin>>n>>m>>v;

    for(int i=0; i<m; i++)
    {
        int a,b; cin>>a>>b;

        node[a].push_back(b);
        node[b].push_back(a);
    }    

    for(int i=1; i<=n; i++)
    {
        sort(node[i].begin(), node[i].end());
    }

    vist[v] = true;
    cout<<v<<" ";
    dfs(v);
    cout<<"\n";

    fill_n(vist,1001, 0); 

    vist[v] = true;
    cout<<v<<" ";
    bfs(v);  
}