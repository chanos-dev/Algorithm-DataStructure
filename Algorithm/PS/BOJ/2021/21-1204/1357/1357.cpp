#include <bits/stdc++.h>
using namespace std; 

int Rev(int d)
{ 
    int j = 1000; 
    while(j != 0)
    {
        if (d / j > 0)
            break;

        j /= 10;
    } 

    int v = 0;

    while (d != 0)
    {
        v += (d % 10) * j;
        j /= 10;
        d /= 10;
    }

    return v;
}

int main()
{
    int x, y; cin>>x>>y;  

    cout<<Rev((Rev(x)+Rev(y)));
}