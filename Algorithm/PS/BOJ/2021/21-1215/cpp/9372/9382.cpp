#include <bits/stdc++.h>
using namespace std;

vector<int> vec[1001];
bool vist[1001];
int cnt = 0;

void check(int i)
{
    for (int v : vec[i])
    {
        if (vist[v])
            continue;

        vist[v] = true; 
        cnt++;
        check(v);
    }
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int t; cin>>t;

    for(int i=0; i<t; i++)
    {
        int n, m; cin>>n>>m;

        for(int j=0; j<m; j++)
        {
            int a,b; cin>>a>>b;

            vec[a].push_back(b);
            vec[b].push_back(a);
        }

        check(1);
        cout<<cnt-1<<"\n";
        cnt = 0;

        for(int j=1; j<=n; j++)
        {
            vec[j].clear();
            vist[j] = false;
        }
    }
}