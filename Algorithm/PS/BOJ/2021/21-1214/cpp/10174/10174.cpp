#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    cin.ignore(256,'\n');

    for(int i=0; i<n; i++)
    {
        string s; getline(cin, s); 

        bool isdiff = false; 

        for(int j=0; j<s.size(); j++)
        {
            if (toupper(s[j]) != toupper(s[s.size() - j - 1]))
            {
                isdiff = true;
                break;
            }
        }


        if (isdiff)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
}