#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    while(true)
    {
        string s;
        getline(cin, s);
        if (s == ".") break;

        stack<char> stk;
        
        for(char c : s)
        {
            if (c == '(' || c == '[') stk.push(c);
            else if (c == ')' || c == ']')
            {
                if (stk.empty())
                {
                    stk.push('.');
                    break;
                }
                int p = abs(c - stk.top());
                if (p > 2) break;
                else stk.pop();
            }
        }

        stk.empty() ? cout<<"yes\n" : cout<<"no\n";
    }
}