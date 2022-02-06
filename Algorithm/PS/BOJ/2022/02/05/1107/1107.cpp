#include<bits/stdc++.h>
using namespace std;

bool broken[10] = {false, };
int check(int n)
{
    if (n == 0 && !broken[n]) return 1;

    int z = 0;
    while(n != 0)
    {
        int c = n % 10;
        if (broken[c]) return 0;
        z++;
        n /= 10;
    }

    return z;
}

int main()
{        
    int n, m; cin>>n>>m;    
    for(int i=0; i<m; i++)
    {
        int b; cin>>b;
        broken[b] = true;
    } 
    
    int ans = abs(100-n);
    for(int i=0; i<=1000000; i++)
    {
        int p = check(i);
        if (p != 0)
            ans = min(ans, abs(i - n) + p);
    }

    cout<<ans;
}