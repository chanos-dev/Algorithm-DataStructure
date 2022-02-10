#include<bits/stdc++.h>
using namespace std;

int dp[1001];

int tile(int v)
{
    if (v == 1) return 1;
    if (v == 2) return 2;
    if (dp[v] != 0) return dp[v];
    return dp[v] = (tile(v-1) + tile(v-2)) % 10007;
}

int main()
{
    int v; cin>>v;
    cout<<tile(v);
}