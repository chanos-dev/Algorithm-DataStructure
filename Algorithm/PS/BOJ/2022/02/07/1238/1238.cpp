#include<bits/stdc++.h>
using namespace std;

#define INF 987654321

vector<pair<int, int>> streets[1001];

int dijkstra(int i, int x)
{
    vector<int> dist(1001, INF);
    priority_queue<pair<int, int>> pq;
    dist[i] = 0;
    pq.push({dist[i], i});

    while(!pq.empty())
    {
        int curDist = pq.top().first * -1;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < curDist) continue;
        for(pair<int, int> c : streets[cur])
        {
            int next = c.first;
            int nextDist = c.second + curDist;

            if (nextDist >= dist[next]) continue;
            dist[next] = nextDist;
            pq.push({nextDist*-1, next});
        }
    }

    return dist[x];
}

int main()
{
    int n, m, x; cin>>n>>m>>x;
    for(int i=0; i<m; i++)
    {
        int a,b,c; cin>>a>>b>>c;

        streets[a].push_back({b,c});
    }
    
    int time = -1;
    for(int i=1; i<=n; i++)
    {
        time = max(time, dijkstra(i, x) + dijkstra(x, i));
    }        

    cout<<time;
}