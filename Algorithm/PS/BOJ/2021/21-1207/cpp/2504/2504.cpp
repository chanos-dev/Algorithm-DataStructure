#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    stack<char> stk;
    string s; cin>>s;

    int sum = 0;
    int temp = 1;
    
    for(int i=0; i<s.size(); i++)
    {
        if (s[i] == ')')
        {
            if (stk.empty() || stk.top() != '(')
            {   
                sum = 0;
                break;
            }

            if (s[i - 1] == '(')
                sum += temp;

            stk.pop();
            temp /= 2;
        }
        else if (s[i] == ']')
        {
            if (stk.empty() || stk.top() != '[')
            {
                sum = 0;
                break;
            }

            if (s[i - 1] == '[')
                sum += temp;

            stk.pop();
            temp /= 3;
        }
        else
        {
            if (s[i] == '(')
                temp *= 2;
            else if (s[i] == '[')
                temp *= 3;

            stk.push(s[i]);
        }
    } 
    
    if (stk.empty() && sum != 0)
        cout<<sum;
    else
        cout<<"0";
}