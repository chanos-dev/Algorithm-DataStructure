#include<bits/stdc++.h>
using namespace std;

#define INF 987654321
int n, m;
vector<pair<int, int>> node[1001];
vector<int> path(1001, 0);  
vector<int> dist(1001);

int dijkstra(int destroy)
{
    priority_queue<pair<int, int>> pq;
    fill(dist.begin(), dist.end(), INF);
    dist[1] = 0;
    pq.push({ dist[1], 1 });

    while (!pq.empty())
    {
        int curDist = pq.top().first * -1;
        int cur = pq.top().second;
        pq.pop();
        
        if (dist[cur] < curDist) continue;
        for (pair<int, int> c : node[cur])
        {
            int next = c.first;
            int nextDist = c.second + curDist;
            if ((cur == path[destroy] && next == destroy) || 
                (next == path[destroy] && cur == destroy)) continue;
            if (nextDist >= dist[next]) continue;
            dist[next] = nextDist;
            if (destroy == 0) path[next] = cur;                
            pq.push({ nextDist * -1, next });
        }
    }

    return dist[n];
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        node[a].push_back({ b,c });
        node[b].push_back({ a,c });
    }

    int pn = n;
    dijkstra(0);
    int ans = dist[n];
    while (pn > 1)
    {
        int d = dijkstra(pn);
        pn = path[pn];
        ans = max(ans, d);        
    } 

    cout << ans;
}