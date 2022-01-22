#include<bits/stdc++.h>
using namespace std;

#define n first
#define d second

vector<pair<int, int>> node[1001];
bool vist[1001];

void check(int a, int b, int d)
{
    if (a == b)
    {
        cout<<d<<"\n";
        return;
    }

    for(pair<int, int> n : node[a])
    {
        if (vist[n.n]) continue;
        vist[n.n] = true;

        check(n.n, b, d + n.d);
    }
}

int main()
{
    int n, m; cin>>n>>m;

    for(int i=0; i<n-1; i++)
    {
        int a, b, c; cin>>a>>b>>c;

        node[a].push_back({b,c});
        node[b].push_back({a,c});
    }
    
    for(int i=0;i <m; i++)
    {
        int a,b; cin>>a>>b;
        fill_n(vist, n+1, false);
        vist[a] = true;
        check(a, b, 0);
    }
}