#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[26] = {0, };
    string str; 
    getline(cin, str);
    
    for(int i=0; i<str.length(); i++)
        arr[str[i] - 97]++;
    
    for(int i=0; i<26; i++)
        cout<<arr[i]<<" ";
}