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
        string str;
        cin>>str;
        cout<<(int)str[0]-'0'+(int)str[2]-'0'<<"\n";
    }
}