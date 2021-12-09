#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    string s; getline(cin, s);

    bool isAsc = false;

    if (s[0] == '1') isAsc = true;

    for(int i=1; i<s.size(); i++)
    {
        if (s[i] == ' ') continue;

        if (isAsc)
        {
            if (s[i-2] + 1 != s[i])
            {
                cout<<"mixed";
                return 0;
            }
        }
        else
        {  
            if (s[i-2] - 1 != s[i])
            {
                cout<<"mixed";
                return 0;
            }
        }
    }

    if (isAsc)
        cout<<"ascending";
    else
        cout<<"descending";
}