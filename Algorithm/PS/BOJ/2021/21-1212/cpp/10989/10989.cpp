#include<bits/stdc++.h>
using namespace std;

int N[10000];

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    
    int n; cin>>n;
    int max = 0;
    for(int i=0; i<n; i++)
    {
        int v; cin>>v;
        N[v-1]++;
        if (v > max) max = v;
    }    

    for(int i=0; i<max; i++)
    {
        for(int j=0; j<N[i];j++)
        {
            cout<<i+1<<"\n";
        }
    }
}