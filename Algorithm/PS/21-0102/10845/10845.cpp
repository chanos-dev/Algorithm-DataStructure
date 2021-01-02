#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int cnt;
    queue<int> queue;
    string str;
    cin>>cnt; 

    for(int i=0; i<cnt; i++)
    {  
        cin>>str;

        if(str=="pop")
        {
            if (queue.empty())
                cout<<"-1\n";
            else
            {  
                cout<<queue.front()<<"\n";
                queue.pop();
            }
        }
        else if(str=="size")
        {
            cout<<queue.size()<<"\n";
        }
        else if(str=="empty")
        {
            if (queue.empty())
                cout<<"1\n";
            else
                cout<<"0\n";                        
        }
        else if(str=="front")
        {
            if (queue.empty())
                cout<<"-1\n";
            else
                cout<<queue.front()<<"\n";
        }
        else if(str=="back")
        {
            if (queue.empty())
                cout<<"-1\n";
            else
                cout<<queue.back()<<"\n";
        }
        else
        {
            int value = 0;
			cin >> value;

            queue.push(value);
        } 
    }
} 