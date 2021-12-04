#include <bits/stdc++.h>
using namespace std;  

int main()
{
    int n; cin>>n;
    cin.ignore(256,'\n');

    for(int i=0; i<n; i++)
    {
        string s;
        getline(cin,s); 

        if (s[0] >= 'a')
        {
            s[0] -= 32;
        }

        cout<<s<<"\n";
    }
}