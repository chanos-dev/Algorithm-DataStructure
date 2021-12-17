#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    while(true)
    {
        string s; cin>>s;

        if (s == "0")
            break;
        
        bool isdiff = false;

        for(int i=0; i<s.size()/2; i++)
        {
            if (s[i] != s[s.size()-1-i])
            {
                isdiff = true;
                break;
            }
        }

        if (isdiff) cout<<"no\n";
        else cout<<"yes\n";        
    }
}