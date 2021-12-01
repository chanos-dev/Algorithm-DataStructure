#include <bits/stdc++.h>
using namespace std;

int main()
{
    int f;
    int cnt = 0;
    cin>>f;
    for(int i=0; i<5; i++)
    {
        int n;
        cin>>n;

        if (f == n)
            cnt++;
    }

    cout<<cnt;
} 