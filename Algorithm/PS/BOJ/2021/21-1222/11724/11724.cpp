#include <bits/stdc++.h>
using namespace std;

vector<int> node[1001];
bool vist[1001];

void check(int i)
{
    for(int n : node[i])
    {
        if (vist[n]) continue;

        vist[n] = true;
        check(n);
    }
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n, m; cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int a, b; cin>>a>>b;

        node[a].push_back(b);
        node[b].push_back(a);
    }

    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
        if(vist[i]) continue;
        cnt++;

        check(i);
    }

    cout<<cnt;
}