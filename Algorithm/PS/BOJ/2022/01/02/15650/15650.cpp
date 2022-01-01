#include<bits/stdc++.h>
using namespace std;

int n,m;

int arr[9];
bool used[9];

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
        if (!used[i])
        {
            arr[k] = i;
            if (k > 0)
            {
                if (arr[k-1] > i)
                    continue;
            }

            used[i] = true;
            nm(k+1);
            used[i] = false;
        }
    }
}

int main()
{
    cin>>n>>m;
    nm(0);
}