#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int i=0; i<t;i++)
    {
        int n;
        int sum = 0;
        cin>>n;

        for(int j=0; j<n; j++)
        {
            int v;
            cin>>v;
            sum+=v;
        }

        cout<<sum<<"\n";
    }
} 