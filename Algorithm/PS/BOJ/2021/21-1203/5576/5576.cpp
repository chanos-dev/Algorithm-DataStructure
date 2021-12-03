#include <bits/stdc++.h>
using namespace std; 

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int W[10] = {0,};
    int K[10] = {0,};

    for(int i=0; i<10; i++)
    {
        int n; cin>>n;
        W[i] = n;
    }
    for(int i=0; i<10; i++)
    {
        int n; cin>>n;
        K[i] = n;
    }

    sort(W, W+10, compare);
    sort(K, K+10, compare);

    cout<<W[0]+W[1]+W[2]<<" "<<K[0]+K[1]+K[2];
}