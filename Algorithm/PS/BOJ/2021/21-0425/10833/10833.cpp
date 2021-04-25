#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;
    cin>>n;

    int apple = 0;

    for(int i=0; i<n; i++)
    {
        int ta, st;

        cin>>st>>ta;

        apple += ta % st;
    }

    cout<<apple;
}