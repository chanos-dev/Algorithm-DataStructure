#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int count = 0;
    list<char> keylogger; 
    list<char> decPass;
    string inputPass;
    bool isMove = false;
    cin>>count;

    for(int i=0; i<count; i++, cout<<"\n")
    {
        decPass.clear();
        keylogger.clear(); 
        cin>>inputPass;

        for(auto word : inputPass)
            keylogger.push_back(word);

        auto cur = decPass.begin();
        
        for(auto word : keylogger)
        {  
            switch (word)
            {
                case '<': 
                    if(cur != decPass.begin()) 
                    {
                        cur--; 
                        isMove = true;
                    }
                    break; 
                case '>':
                    if(cur != decPass.end())
                    {
                        cur++;
                        isMove = true;
                    }
                    break;
                case '-':
                    if(!decPass.empty())
                    {
                        if(cur != decPass.begin())
                        {
                            cur--;  
                            cur = decPass.erase(cur);
                        } 
                    }
                    break;
                default: 
                    decPass.insert(cur, word);
                    if(cur != decPass.end() && !isMove)
                        cur++; 
                    break;
            }
        }

        for(auto word : decPass)
            cout<<word;  
    } 
}
//ABC<<DE-<A<<-------- => AADBC
