#include <bits/stdc++.h>
#include <string>
using namespace std;  

int main()
{
    int n,m; cin>>n>>m;   
    string s = "";

    for(int i=0; i<n; i++)
    {
        s += to_string(n);
    }

    if (s.length() >= m)
    {
        cout<<s.substr(0, m);
        return 0;
    }

    cout<<s;
}