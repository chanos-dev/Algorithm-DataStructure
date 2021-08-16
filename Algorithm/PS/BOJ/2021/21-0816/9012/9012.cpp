#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    int n;    
    cin>>n;

    for(int i=0; i<n; i++)
    {
        bool isNo = false;
        stack<char> stk;        
        string str;
        cin>>str;

        for(int j=0;j<str.length();j++)
        {
            if (j==0 && str[j] == ')')
            {
                cout<<"NO\n";
                isNo = true;
                break;
            }

            if (str[j] == '(')
                stk.push(str[j]);

            if (str[j] == ')')
            {
                if (stk.empty())
                { 
                    cout<<"NO\n";
                    isNo = true;
                    break;
                }
                else
                { 
                    stk.pop();
                }
            } 
        }

        if (stk.empty() && !isNo)
            cout<<"YES\n"; 
        else if (!stk.empty())
            cout<<"NO\n";         
    }
}