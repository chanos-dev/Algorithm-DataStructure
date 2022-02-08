#include<bits/stdc++.h>
using namespace std;

#define INF 987654321

vector<pair<int, int>> country[300001];
vector<int> dist(300001, INF);

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
        for(pair<int, int> c : country[cur])
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
    int n, m, k, x; cin>>n>>m>>k>>x;
    for(int i=0; i<m; i++)
    {
        int a,b; cin>>a>>b;
        country[a].push_back({b, 1});
    }

    bool isexist = false;
    dijkstra(x);
    for(int i=1; i<=n; i++)
    {
        if (dist[i] == k) 
        {
            isexist = true;
            cout<<i<<"\n";
        }
    }

    if (!isexist) cout<<"-1";
}