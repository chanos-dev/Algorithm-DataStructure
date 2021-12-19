#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int t; cin>>t;

    while(t--)
    {
        string a, b; cin>>a>>b;

        int str[27] = {0,};

        for(int i=0; i<a.size(); i++)
        {
            str[a[i]-'a']++;
        } 

        for(int i=0; i<b.size(); i++)
        {            
            str[b[i]-'a']--;
        }

        bool isdiff = false;
        for(int i=0; i<27; i++)
        {
            if (str[i] != 0)
            {
                isdiff = true;
                break;
            }
        }

        if (isdiff)
            cout<<a<<" & "<<b<<" are NOT anagrams.\n";
        else
            cout<<a<<" & "<<b<<" are anagrams.\n";
    }
}