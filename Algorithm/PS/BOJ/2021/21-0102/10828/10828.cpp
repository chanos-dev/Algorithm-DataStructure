#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int cnt;
    stack<int> stack;
    string str;
    cin>>cnt; 

    for(int i=0; i<cnt; i++)
    {  
        cin>>str;

        if(str=="pop")
        {
            if (stack.empty())
                cout<<"-1\n";
            else
            { 
                cout<<stack.top()<<"\n";
                stack.pop();
            }
        }
        else if(str=="size")
        {
            cout<<stack.size()<<"\n";
        }
        else if(str=="empty")
        {
            if (stack.empty())
                cout<<"1\n";
            else
                cout<<"0\n";                        
        }
        else if(str=="top")
        {
            if (stack.empty())
                cout<<"-1\n";
            else
                cout<<stack.top()<<"\n";
        }
        else
        {
            int value = 0;
			cin >> value;

            stack.push(value);
        } 
    }
} 