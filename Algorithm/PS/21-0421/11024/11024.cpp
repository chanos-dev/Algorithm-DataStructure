#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int t;

    cin>>t;

    cin.ignore(256, '\n');

    for(int i=0; i<t; i++)
    {
        int sum = 0;
        string n;        
        string temp;

        getline(cin,n); 

        for(int j=0; j<n.length(); j++)
        {
            temp += n[j];  

            if(n[j] == ' ' || j == n.length() -1)
            { 
                sum += stoi(temp);
                temp = "";
                continue;
            }      
        }

        cout<<sum<<"\n";
    }
}