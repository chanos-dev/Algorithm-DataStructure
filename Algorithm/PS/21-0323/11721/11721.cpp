#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    string str;

    cin>>str; 
    
    while(str.length() != 0)
    {
        cout<<str.substr(0, 10)<<"\n"; 

        if (str.length() < 10) break;

        str = str.substr(10, str.length());
    }
}