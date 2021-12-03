#include <bits/stdc++.h>
using namespace std; 

int main()
{
    string s; cin>>s;
    bool isFirst = true;

    for(int i=0; i<s.size(); i++)
    {
        if (s[i] == '-')
        {
            isFirst = true;
            continue;
        }

        if(isFirst)
        {
            cout<<s[i];
            isFirst = false;
        } 
    }
}