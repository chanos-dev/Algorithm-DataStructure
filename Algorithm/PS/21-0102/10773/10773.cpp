#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int cnt;
    stack<int> stack; 

    cin>>cnt;  

    for(int i=0; i<cnt; i++)
    {
        int value;
        cin>>value;
        if (value == 0)
        {
            if (!stack.empty())
                stack.pop();
        }
        else
        {
            stack.push(value);
        }     
    }

    int sum = 0;
    int size = stack.size();
    for(int i=0; i<size; i++)
    {
        if (!stack.empty())
        {
            sum += stack.top(); 
            stack.pop();
        }        
    }

    cout<<sum;
} 