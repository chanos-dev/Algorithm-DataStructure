#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[9];
int used[10001];
set<int> s;

void nm(int k)
{
    if (k == m)
    {
        for(int i=0; i<m; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";  

        return;
    }

    for(int i : s)
    {
        if (used[i] < 1) continue;

        arr[k] = i;
        used[i]--;
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