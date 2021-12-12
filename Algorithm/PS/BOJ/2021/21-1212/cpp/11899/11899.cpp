#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin>>s;

    stack<char> stk;

    for(char c : s)
    {
        if (c == ')' && !stk.empty())
        {
            if (stk.top() == '(')
            {
                stk.pop();
                continue;
            }
        } 

        stk.push(c);
    }

    cout<<stk.size();
}