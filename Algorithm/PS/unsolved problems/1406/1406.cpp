#include <bits/stdc++.h>
using namespace std;

int cur = 0; 
string str;

void SetCursor(char cmd)
{
    if(cmd == 'L')
    {
        cur--;
        if(cur < 0) cur = 0;
    }
    else if(cmd == 'D')
    {
        cur++;
        if(cur >= str.length()) cur = str.length();
    }  
}

void Vim(string cmd)
{
    if( (cmd[0] == 'L') || (cmd[0] == 'D'))
        SetCursor(cmd[0]);
    else if(cmd[0] == 'B')
    {
        if(cur == 0)
            return;
        
        str.erase(cur-1,1);   
        SetCursor('L');
    }
    else if(cmd[0] == 'P')
    {   
        str.insert(cur, 1, cmd[2]); 
        SetCursor('D');
    }  
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    getline(cin, str);    

    cur = str.length();

    int count;
    cin>>count; 
    cin.ignore(256,'\n'); 

    for(int i=0; i<count; i++)
    {
        string input;
        getline(cin,input);

        Vim(input);
    }

    cout<<str;
}