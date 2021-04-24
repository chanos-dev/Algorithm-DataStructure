#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    int strarr1[26] = {0,}, strarr2[26] = {0,};

    int count;
    cin>>count; 

    for(int i=0; i<count; i++)
    {
        string str1, str2;
        bool isPossible = true;

        cin>>str1>>str2;

        for(int i=0; i<str1.length(); i++)
        {
            strarr1[str1[i]-'a']++;
            strarr2[str2[i]-'a']++;
        }

        for(int i=0; i<26; i++)
        {
            if(strarr1[i] != strarr2[i]) 
                isPossible = false;  

            strarr1[i] = 0;
            strarr2[i] = 0;
        }

        isPossible ? cout<<"Possible\n" : cout<<"Impossible\n";
    }
}