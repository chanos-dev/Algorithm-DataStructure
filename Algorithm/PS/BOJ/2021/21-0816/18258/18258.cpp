#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    int n;
    queue<int> q;

    cin>>n;

    while(n--)
    {
        string str;
        cin>>str;

        if (str == "push")
        {
            int x;
            cin>>x;
            q.push(x);
        }
        else if (str == "pop")
        {
            if (q.empty())
            {
                cout<<"-1\n";
            }
            else
            {
                cout<<q.front()<<"\n";
                q.pop();
            }
        }
        else if (str == "size")
        {
            cout<<q.size()<<"\n";
        }
        else if (str == "empty")
        {
            cout<<q.empty()<<"\n";
        }
        else if (str == "front")
        {
            if (q.empty())
            {
                cout<<"-1\n";
            }
            else
            {
                cout<<q.front()<<"\n";
            }
        }
        else if (str == "back")
        {
            if (q.empty())
            {
                cout<<"-1\n";
            }
            else
            {
                cout<<q.back()<<"\n";
            }
        }
    }
}