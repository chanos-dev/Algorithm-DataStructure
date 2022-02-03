#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> node[10001];
bool vist[10001];
int maxNode, maxValue;

void dfs(int n, int k)
{
    if (vist[n]) return; 
    vist[n] = true;

    if (maxValue < k)    
    {
        maxNode = n;
        maxValue = k;
    }

    for(pair<int, int> c : node[n])
        dfs(c.first, c.second + k);
} 

int main()
{
    int k; cin>>k;
    
    for(int i=0; i<k-1; i++)
    {
        int a, b, c; cin>>a>>b>>c;

        node[a].push_back({b, c});
        node[b].push_back({a, c});
    }     
    dfs(1, 0); 
    fill_n(vist, 10001, false);
    maxValue = 0;
    dfs(maxNode, 0);
    cout<<maxValue;
}