#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    string str1, str2;
    cin>>str1>>str2;
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    if(str1>str2)
        cout<<str1;
    else
        cout<<str2;
}