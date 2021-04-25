#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int t;
    cin>>t;

    for(int i=0; i<9; i++)
    {
        int p;
        cin>>p;

        t -= p;
    }

    cout<<t;
}