#include <bits/stdc++.h>
using namespace std;

bool Sequence(queue<int> input, queue<char> &cmd)
{
    int size = input.size(); 

    int pos = 0;
    int n = input.front();
    input.pop(); 

    while(cmd.size() != size)
    {
        if(pos == n)
        {
            pos--;
            cmd.push('-');
            n = input.front();
            input.pop();  
            return true;
        }
        else if(pos <= n)
        { 
            pos++;
            cmd.push('+');
        }        
    }

    return true;
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int cnt;
    queue<int> input; 
    queue<char> cmd;

    cin>>cnt;

    for(int i=0; i<cnt; i++)
    {
        int value;
        cin>>value;        
        input.push(value);
    } 

    if(Sequence(input, cmd))
    {
        while(!cmd.empty())
        {
            cout<<cmd.front()<<"\n";
            cmd.pop();
        }
    }
    else
    {
        cout<<"NO";        
    }
    
} 