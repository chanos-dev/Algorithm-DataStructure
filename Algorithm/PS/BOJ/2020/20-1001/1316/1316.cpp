#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);   

    string str;
    int n;    

    cin>>n;
    cin.ignore(256,'\n'); 

    int count = n;

    for(int i=0; i<n; i++)
    {
        int al[26] = {0, };  

        getline(cin,str);        

        for(int j=0; j<str.length(); j++)
        { 
            if(al[str[j]-'a'] == 0)
                al[str[j]-'a'] = j+1;
            else
            {
                if(al[str[j]-'a'] != j)
                { 
                    count--;
                    break;
                }             
                else
                    al[str[j]-'a'] = j+1;  
            } 
        }
    }

    cout<<count;
}