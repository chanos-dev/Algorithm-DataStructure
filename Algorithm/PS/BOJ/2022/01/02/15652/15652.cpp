#include<bits/stdc++.h>
using namespace std;

int n, m;
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

    for(int i=1; i<=n; i++)
    {
        if (k > 0)
        {
            if (arr[k-1] > i)
                continue;
        }

        arr[k] = i;
        nm(k+1);
    }
}

int main()
{
    cin>>n>>m;
    nm(0);
}