#include <bits/stdc++.h>
using namespace std;

int dp[1001] = {0,};

int tile(int n)
{
    if (n <= 1)
        return 1;
    else if (dp[n] == 0)
        return dp[n] = (tile(n - 1) + tile (n - 2) * 2) % 10007;
    
    return dp[n];
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; cin>>n;
    cout<<tile(n);
}