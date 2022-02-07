#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> node[50001];
vector<int> v(50001, 987654321);
int n, m; 

void dijkstra()
{    
    priority_queue<pair<int, int>> pq;
    pq.push({1, 0});
    v[1] = 0;

    while(!pq.empty())
    {        
        int cur = pq.top().first; 
        int dist = pq.top().second * -1;
        pq.pop();

        if (v[cur] < dist) continue;

        for(int i=0; i<node[cur].size(); i++)
        {
            int next = node[cur][i].first;
            int ndist = node[cur][i].second + dist;

            if (ndist >= v[next]) continue;

            v[next] = ndist;
            pq.push({next, ndist * -1});
        } 
    }
}

int main()
{
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int a,b,c; cin>>a>>b>>c;

        node[a].push_back({b,c});
        node[b].push_back({a,c});
    }

    dijkstra();
    cout<<v[n];
}