#include<bits/stdc++.h>
using namespace std;

#define INF 987654321

vector<pair<int, int>> node[20001];
vector<int> dist(20001, INF);

void dijkstra(int k)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, k});
    dist[k] = 0;

    while(!pq.empty())
    {        
        int curDist = pq.top().first * -1;
        int cur  = pq.top().second;
        pq.pop();

        if (dist[cur] < curDist) continue;
        for(pair<int, int> c : node[cur])
        {
            int next = c.first;
            int nextDist = c.second + curDist;

            if (nextDist >= dist[next]) continue;

            dist[next] = nextDist;
            pq.push({nextDist * -1, next});
        } 
    }
}

void print(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(dist[i] == INF)        
            cout<<"INF\n";
        else
            cout<<dist[i]<<"\n";
    }
}

int main()
{    
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int v,e; cin>>v>>e;
    int k; cin>>k;

    for(int i=0; i<e; i++)
    {
        int a, b, c; cin>>a>>b>>c;

        node[a].push_back({b, c});
    }

    dijkstra(k);
    print(v);
}