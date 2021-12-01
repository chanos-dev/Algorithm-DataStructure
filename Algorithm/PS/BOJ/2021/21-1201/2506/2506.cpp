#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int k = 1;
    int s = 0;
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
        int q;
        cin>>q;

        if (q == 1)
        {
            s += k++;
        }
        else
        {
            k = 1;
        }
    }

    cout<<s;
} 