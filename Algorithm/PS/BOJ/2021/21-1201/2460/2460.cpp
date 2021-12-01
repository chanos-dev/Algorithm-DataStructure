#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m = 0, n = 0;;

    for (int i=0; i<10; i++)
    {
        int gi, go;
        cin>>go>>gi;

        n += (gi - go);

        if (m <= n)
            m = n;
    } 

    cout<<m;
}