#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    string str1, str2;
    int arr1[26] = {0, };
    int arr2[26] = {0, };
    int count = 0;

    cin>>str1>>str2;

    for(int i=0; i<str1.length(); i++)
        arr1[str1[i] - 'a']++;
    
    for(int i=0; i<str2.length(); i++)
        arr2[str2[i] - 'a']++;

    for(int i=0; i<26; i++) 
        if(arr1[i] != arr2[i])
            count += abs(arr1[i] - arr2[i]); 

    cout<<count;    
}