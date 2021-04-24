#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int cnt;
    deque<int> deque;
    string str;
    cin>>cnt; 

    for(int i=0; i<cnt; i++)
    {  
        cin>>str;

        if (str == "push_front")
        {
            int val;
            cin>>val;
            deque.push_front(val);
        }
        else if (str == "push_back")
        {
            int val;
            cin>>val; 
            deque.push_back(val);
        }
        else if (str == "pop_front")
        {
            if (deque.empty())
                cout<<"-1\n";
            else
            {
                cout<<deque.front()<<"\n";
                deque.pop_front();
            }
        }
        else if (str == "pop_back")
        {
            if (deque.empty())
                cout<<"-1\n";
            else
            {
                cout<<deque.back()<<"\n";
                deque.pop_back();
            }
        }
        else if (str == "size")
        {
            cout<<deque.size()<<"\n";
        }
        else if (str == "empty")
        {
            if (deque.empty())
                cout<<"1\n";
            else
                cout<<"0\n"; 
        }
        else if (str == "front")
        {
            if (deque.empty())
                cout<<"-1\n";
            else
                cout<<deque.front()<<"\n";
            
        }
        else if (str == "back")
        {
            if (deque.empty())
                cout<<"-1\n";
            else
                cout<<deque.back()<<"\n";
        } 
    }
} 