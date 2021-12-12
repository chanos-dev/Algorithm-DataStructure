#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int N[91] = {0,};

    N[0] = 0;
    N[1] = 1;

    for(int i=2; i<91; i++)
    {
        N[i] = N[i-1] + N[i-2];
    }

    int n; cin>>n;
    cout<<N[n];
}