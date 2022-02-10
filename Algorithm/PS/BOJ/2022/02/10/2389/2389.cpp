#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;

    int cnt = 0; 

    while(n >= 0)
    {
        if (n % 5 == 0)
        {
            cnt += n/5;
            cout<<cnt;
            return 0;
        }

        cnt++;
        n-=3;
    }

    cout<<"-1";
}