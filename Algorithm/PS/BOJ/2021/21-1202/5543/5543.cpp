#include <bits/stdc++.h>
using namespace std;

int main()
{    
    int h = 2001;
    int d = 2001;

    for(int i=0; i<5; i++)
    {
        int n; cin>>n;

        if (i < 3)
        {
            if (h >= n)
            {
                h = n;
            }
        }
        else
        {
            if (d >= n)
                d = n;
        }
    }

    cout<<h+d-50;
}