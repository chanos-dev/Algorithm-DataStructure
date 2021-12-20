#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n, m; cin>>n>>m;

    while(n--)
    {
        string s; cin>>s;

        for(int h=0, t=m-1; h<m/2; h++, t--)
        {
            if (s[h] != '.')
                s[t] = s[h];
            else
                s[h] = s[t];
        }

        cout<<s<<"\n";
    }
} 