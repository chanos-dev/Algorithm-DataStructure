#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int t = 0;

    for(int i=0; i<n; i++)
    {
        int m;
        cin>>m;

        t += m;
    }

    cout<<t-(n-1);
}