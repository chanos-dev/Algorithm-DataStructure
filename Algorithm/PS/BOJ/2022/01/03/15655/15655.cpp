#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec;

int arr[9];
bool used[9];

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

    for(int i=0; i<n; i++)
    {
        if (!used[i])
        {
            if (k > 0)
            {
                if (arr[k-1] > vec[i])
                    continue;
            }

            arr[k] = vec[i];
            used[i] = true;
            nm(k+1);
            used[i] = false;
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        int v; cin>>v;
        vec.push_back(v);
    }
    sort(vec.begin(), vec.end());
    nm(0);
}