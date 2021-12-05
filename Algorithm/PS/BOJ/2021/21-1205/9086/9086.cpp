#include <bits/stdc++.h>
using namespace std;  

int main()
{
    int n; cin>>n;

    for(int i=0; i<n; i++)
    {
        string s; cin>>s;

        if (s.length() < 2)
        {
            cout<<s<<s<<"\n";
        }
        else
        {
            cout<<s[0]<<s[s.length()-1]<<"\n";
        }
    } 
}