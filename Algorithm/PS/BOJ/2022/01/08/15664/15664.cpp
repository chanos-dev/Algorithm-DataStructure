#include<bits/stdc++.h>
using namespace std;

int n,m;
set<int> s;

int arr[9];
int used[10001];

void nm(int k)
{
    if (k == m)
    {
        for(int i=0; i<m; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i : s)
    {
        if (used[i] < 1) continue;
        if (k > 0 && arr[k-1] > i) continue;
        used[i]--;
        arr[k] = i;
        nm(k+1);
        used[i]++;
    }
}

int main()
{
    cin>>n>>m;

    for(int i=0; i<n; i++) 
    {
        int v; cin>>v;
        s.insert(v);
        used[v]++;
    }

    nm(0);
}