#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    string str;
    int al[26] = {0, };
    cin>>str;

    for(int i=0; i<str.length(); i++)
    {
        if(str[i] >= 'a') 
            al[str[i] - 'a']++;
        else 
            al[str[i] - 'A']++;
    }

    int count = 0;
    int max = -1;
    int index = 0;

    for(int i=0; i<26; i++) 
        if(al[i] > max)
        { 
            max = al[i];
            index = i;
        } 

    for(int i=0; i<26; i++)  
        if(max == al[i]) count++; 

    if(count == 1)
        cout<<(char)(index+'A');
    else
        cout<<"?";
}