#include <bits/stdc++.h>
using namespace std;

int oneH = 1'000'000;

int arr[2000005];

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; cin>>n;
    int maxV = -1;
    for(int i=0; i<n; i++)
    {
        int v; cin>>v;
        arr[v+oneH]++;
        maxV = max(maxV, v+oneH);
    }

    for(int i=0; i<=maxV; i++)
    {
        for(int j=0; j<arr[i]; j++)
            cout<<i-oneH<<"\n";
    }
}