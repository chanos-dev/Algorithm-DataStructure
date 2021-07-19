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
    
    int n, m;
    int count = 0;

    cin>>n;

    for (int i=0; i<n; i++)
    {
        int temp;

        cin>>m;

        if (prime(m))
            count++;
    }

    cout<<count;
}