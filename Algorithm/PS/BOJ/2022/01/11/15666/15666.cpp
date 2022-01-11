#include<bits/stdc++.h>
using namespace std;

int n, m;
set<int> s;

int arr[9]; 

void nm(int k)
{
    if (k == m)
    {
        for(int i=0; i<m; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }

    for(int v : s)
    {
        if (k > 0 && arr[k-1] > v)
        {
            continue;
        }

        arr[k]=v;
        nm(k+1);
    }
}

int main()
{
    cin>>n>>m;

    for(int i=0; i<n; i++)
    {
        int v; cin>>v;
        s.insert(v);
    }

    nm(0);
}