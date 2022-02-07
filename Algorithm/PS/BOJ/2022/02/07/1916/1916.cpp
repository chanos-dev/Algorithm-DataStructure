#include<bits/stdc++.h>
using namespace std;

#define INF 987654321

vector<pair<int, int>> city[1001];
vector<int> dist(1001, INF);

void dijkstra(int s)
{
    priority_queue<pair<int, int>> pq;    
    dist[s] = 0;
    pq.push({dist[s], s});

    while(!pq.empty())
    {
        int curDist = pq.top().first * -1;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < curDist) continue;
        for(pair<int, int> c : city[cur])
        {
            int next = c.first;
            int nextDist = c.second + curDist;
            if (nextDist >= dist[next]) continue;

            dist[next] = nextDist;
            pq.push({nextDist * -1, next});
        }
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

        city[a].push_back({b, c});
    }

    int s,e; cin>>s>>e;
    dijkstra(s);
    cout<<dist[e];
}