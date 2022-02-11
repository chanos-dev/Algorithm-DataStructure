#include<bits/stdc++.h>
using namespace std;

#define INF 987654321

int v,e,p;
int t;
vector<pair<int, int>> node[5001];
int dist[5001];

void dijkstra(int s)
{
    for(int i=1; i<=v; i++)
        dist[i] = INF;

    priority_queue<pair<int, int>> pq;
    dist[s] = 0;
    pq.push({dist[s], s});
    while(!pq.empty())
    {
        int curDist = pq.top().first * -1;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < curDist) continue;
        for(pair<int, int> p : node[cur])
        {
            int next = p.first;
            int nextDist = p.second + curDist;
            if (nextDist >= dist[next]) continue;
            dist[next] = nextDist;
            pq.push({nextDist * -1, next});
        }
    }
}

int main()
{
    cin>>v>>e>>p;
    for(int i=0; i<e; i++)
    {
        int a,b,c; cin>>a>>b>>c;
        node[a].push_back({b,c});
        node[b].push_back({a,c});
    }

    dijkstra(1);
    int o = dist[v];
    int pu = dist[p];
    dijkstra(p);
    int oo = dist[v];

    if (oo + pu > o) cout<<"GOOD BYE";
    else cout<<"SAVE HIM";
}