#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> node[100001];
bool vist[100001];
int maxValue, maxNode;

void dfs(int n, int k)
{
    if (vist[n]) return;
    vist[n] = true;

    if (maxValue < k)
    {
        maxValue = k;
        maxNode = n;
    }

    for(pair<int, int> c : node[n])
        dfs(c.first, k + c.second);
}

int main()
{
    int n; cin>>n;

    for(int i=0; i<n; i++)
    {
        int a; cin>>a;
        int n[2];

        int idx = 0;
        while(true)
        {
            cin>>n[idx];
            if (n[idx] == -1) break;            
            idx++;
            if (idx == 2)            
            {
                idx = 0;
                node[a].push_back({n[0], n[1]});
                node[n[0]].push_back({a, n[1]});
            }
        }
    }

    dfs(1, 0);
    maxValue = 0;
    fill_n(vist, 100001, false);
    dfs(maxNode, 0);
    cout<<maxValue;
}