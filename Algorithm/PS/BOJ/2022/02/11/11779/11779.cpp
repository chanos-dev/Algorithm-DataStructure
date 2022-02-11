#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 10000000009

vector<pair<int, ll>> node[1001];
vector<ll> dist(1001, INF);
vector<int> path(1001, 0);

void dijkstra(int s, int e)
{
    priority_queue<pair<ll, int>> pq;
    dist[s] = 0;
    pq.push({dist[s], s});

    while(!pq.empty())
    {
        int curDist = pq.top().first * -1;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < curDist) continue;
        for(pair<int, int> c : node[cur])
        {
            int next = c.first;
            int nextDist = c.second + curDist;

            if (nextDist >= dist[next]) continue;
            dist[next] = nextDist;
            path[next] = cur;
            pq.push({nextDist * -1, next});
        }
    }

    cout<<dist[e]<<"\n";
    stack<int> stk;
    stk.push(e);
    int t = e;
    while(t != s)
    {        
        stk.push(path[t]);
        t = path[t];
    }
    cout<<stk.size()<<"\n";
    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    int n, m; cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int a,b,c; cin>>a>>b>>c;
        node[a].push_back({b,c});        
    }
    int s, e; cin>>s>>e;
    dijkstra(s, e);    
}