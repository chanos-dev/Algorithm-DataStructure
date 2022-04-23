#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; cin>>n;
    string str; cin>>str;
    long long hash = 0;
    
    for(int idx=0; idx<str.length(); idx++)
    {
        int v = (str[idx] - 'a') + 1;
        hash += (v * pow(31, idx)); 
    }
    cout<<hash % 1234567891;
}