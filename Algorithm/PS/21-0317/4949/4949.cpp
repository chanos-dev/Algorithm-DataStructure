#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);     
    
    while(true)
    {  
        stack<char> stack;
        string str;
        bool isFirstExit = false;

        getline(cin, str);

        if (str == ".")
            break;

        for(int idx = 0; idx < str.length(); idx++)
        {
            if (str[idx] == '(' || str[idx] == '[')
                stack.push(str[idx]);
            
            if (str[idx] == ')' || str[idx] == ']')
            {                
                if (stack.empty())
                {
                    isFirstExit = true;
                    cout<<"no\n";
                    break;                
                }

                int n = abs(stack.top() - str[idx]);
                
                if (n > 2)
                { 
                    break; 
                } 
                else
                {
                    if (!stack.empty())
                        stack.pop();
                }
            } 
        } 

        if (!isFirstExit)
        {
            if (stack.size() == 0) 
                cout<<"yes\n"; 
            else
                cout<<"no\n";
        } 
    }
}

// 1 or 2