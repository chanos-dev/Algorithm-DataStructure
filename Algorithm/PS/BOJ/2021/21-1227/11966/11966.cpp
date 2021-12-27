#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; cin>>n;

    if (n == 1)
    {
        cout<<"1";
        return 0;
    }

    int d = 2;
    for(int i=1; i<=30; i++, d*=2)
    {
        if (d == n)
        {
            cout<<"1";
            return 0;
        }
    }

    cout<<"0";
}