#include <bits/stdc++.h>
using namespace std;  

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);   

    string str;  
    cin>>str;

    list<char> editStr; 
    for(auto w : str)
        editStr.push_back(w); 

    auto cur = editStr.end();

    int count;
    cin>>count;

    while(count--)
    {
        char cmd;
        cin>>cmd; 

        if(cmd == 'L')
        {
            if(editStr.begin() != cur)
                cur--; 
        }
        else if(cmd == 'D')
        {
            if(editStr.end() != cur)
                cur++;  
        }
        else if(cmd == 'B')
        {   
            if(editStr.begin() != cur)
            {
                cur--;
                cur = editStr.erase(cur);                       
            }
        }
        else if(cmd == 'P')
        {   
            char addword;
            cin>>addword;
            editStr.insert(cur, addword);  
        }  
    }

    for(auto i : editStr) 
        cout<<i; 
} 