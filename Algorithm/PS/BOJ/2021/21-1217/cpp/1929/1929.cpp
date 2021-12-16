#include <bits/stdc++.h>
using namespace std;

bool prime(int n)
{
    if (n < 2) return false;

    for(int i=2; i*i<=n; i++)
    {
        if (n % i == 0) return false;
    }

    return true;
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 
    
    int m, n; cin>>m>>n;

    for (int i=m; i<=n; i++)
    {
         if (prime(i))
            cout<<i<<"\n";
    } 
}