#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int al[26] = {0, };
    string str;
    
    cin>>str;

    for(int i=0; i<str.length(); i++)
    {
        if(al[str[i] - 'a'] == 0)
            al[str[i] - 'a'] = i+1;
    }
    
    for(int i=0; i<26; i++)
        (al[i] == 0) ? cout<<"-1 " : cout<<al[i]-1<<" ";
}