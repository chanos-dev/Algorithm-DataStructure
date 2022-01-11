#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1, op, s2;
    cin>>s1>>op>>s2;

    string ans;

    if (op == "*")
    {
        ans = s1;
        for(char c : s2)
        {
            if (c == '0')
                ans += "0";
        }
    }
    else
    { 
        if (s1 == "1" && s2 == "1") ans = "2";
        else
        {
            int n = 0;
            string o;

            if (s1 > s2)
            {
                ans = s1;
                o = s2;
            }
            else
            {                
                ans = s2;
                o = s1;
            }

            for(char c : o)
            {
                if (c == '0')
                    n++;
            }

            if (ans[ans.size()-n-1] == '1') ans.replace(ans.size()-n-1, 1, "2");
            else ans.replace(ans.size()-n-1, 1, "1");
        }
    } 

    cout<<ans;
}