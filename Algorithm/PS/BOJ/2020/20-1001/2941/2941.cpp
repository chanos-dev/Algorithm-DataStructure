#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    string str;
    string::size_type npos;  

    const string croa[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="}; 

    getline(cin, str);   

    for(int i=0; i<8; i++)
    {            
        do
        {             
            npos = str.find(croa[i]); 

            if(npos != string::npos)
            {      
                if(croa[i] == "dz=") 
                    str.replace(npos, 3, "a"); 
                else  
                    str.replace(npos, 2, "a");  
            }             
        }while(npos != string::npos); 
    } 
    cout<<str.length();
}