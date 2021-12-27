#include <bits/stdc++.h>
using namespace std;


void bit(long long int n)
{
    if (n != 1)
    {
        bit(n / 2);
    }
    cout<<n % 2;
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    long long int n; cin>>n;
    bit(n);
}