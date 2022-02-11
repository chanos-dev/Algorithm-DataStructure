#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ground[101];
vector<int> number(101, 0);
int ans = 0;
int n,m,r; 

void dijkstra(int s)
{
    vector<int> dist(101, 987654321);
    priority_queue<pair<int, int>> pq;
    dist[s] = 0;
    pq.push({dist[s], s});

    while(!pq.empty())
    {
        int curDist = pq.top().first * -1;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < curDist) continue;
        for(pair<int, int> g : ground[cur])
        {
            int next = g.first;
            int nextDist = g.second + curDist;
            if (nextDist >= dist[next]) continue;
            dist[next] = nextDist;
            pq.push({nextDist * -1, next});
        }
    }
    int item = 0;
    for(int i=1; i<=n; i++)
    {
        if (dist[i] > m) continue;
        item += number[i];
    }

    ans = max(ans, item);
}

int main()
{
    cin>>n>>m>>r;
    for(int i=1; i<=n; i++)
        cin>>number[i];

    for(int i=0; i<r; i++)
    {
        int a,b,c; cin>>a>>b>>c;
        ground[a].push_back({b, c});
        ground[b].push_back({a, c});
    }

    for(int i=1; i<=n; i++)
        dijkstra(i);

    cout<<ans;
}