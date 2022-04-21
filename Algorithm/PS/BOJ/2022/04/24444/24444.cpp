#include <bits/stdc++.h>
using namespace std;

set<int> node[100001];
bool vist[100001];
int vistIdx[100001];

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n, m, r;
    cin>>n>>m>>r;

    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        node[a].insert(b);
        node[b].insert(a);
    }

    int val = 1;
    queue<int> q;    
    q.push(r);
    vist[r] = true;
    vistIdx[r] = val++;
    while(!q.empty())
    {
        int p = q.front(); q.pop(); 

        for(int n : node[p])
        {
            if (vist[n]) continue;
            vist[n] = true;
            vistIdx[n] = val++;
            q.push(n);
        }  
    }

    for(int i=1; i<=n; i++)    
        cout<<vistIdx[i]<<"\n";
}