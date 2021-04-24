#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;

    cin>>n;

    for(int i=0; i<n; i++)
    {
        int r;
        string str;
        cin>>r>>str; 

        for(int j=0; j<str.length(); j++) 
            for(int k=0; k<r; k++)
                cout<<str[j]; 
        cout<<"\n";
    }
}