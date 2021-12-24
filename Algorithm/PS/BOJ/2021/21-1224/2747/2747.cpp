#include<bits/stdc++.h>
using namespace std;

int dp[45];

long Fibo(int n)
{
    if (dp[n] != 0) return dp[n];

    dp[n] = Fibo(n-2) + Fibo(n-1);
    
    return dp[n];
}

int main()
{
    int n; cin>>n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;     
    cout<<Fibo(n);
}