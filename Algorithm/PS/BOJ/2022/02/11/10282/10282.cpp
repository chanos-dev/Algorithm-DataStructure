#include<bits/stdc++.h>
using namespace std;

#define INF 987654321

vector<pair<int, int>> com[10001];

void dijkstra(int n, int s)
{
    vector<int> path(10001, 0);
    vector<int> time(10001, INF);
    priority_queue<pair<int, int>> pq;
    time[s] = 0;
    pq.push({time[s], s});

    while(!pq.empty())
    {
        int curTime = pq.top().first * -1;
        int cur = pq.top().second;
        pq.pop();
        if (time[cur] < curTime) continue;
        for(pair<int, int> c : com[cur])
        {
            int next = c.first;
            int nextTime = c.second + curTime;

            if (nextTime >= time[next]) continue;
            time[next] = nextTime;
            path[next] = cur;
            pq.push({nextTime * -1, next});
        }
    }
    
    int ans = 0;
    int maxV = -1; 

    for(int i=1; i<=n; i++)
    {
        if (path[i] != 0) ans++;
        if (time[i] == INF) continue;
        maxV = max(maxV, time[i]);
    }

    cout<<ans+1<<" "<<maxV<<"\n";
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,d,c; cin>>n>>d>>c;
        for(int i=0; i<d; i++)
        {
            int a,b,c; cin>>a>>b>>c;
            com[b].push_back({a, c});
        }
        dijkstra(n, c);
        for(int i=1; i<=n; i++)
            com[i].clear();
    }
}