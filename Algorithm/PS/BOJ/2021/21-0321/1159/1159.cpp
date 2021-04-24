#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n, count = 0; 
    int basket[26] = {0, };    
    string player;

    cin>>n;

    cin.ignore(256,'\n');

    for (int i=0; i<n; i++)
    {
        getline(cin, player);

        basket[player[0]-97]++;
    }

    for (int i=0; i<26; i++)
    {
        if (basket[i] >= 5)
        {
            cout<<(char)(i+97);
            count++;
        }
    }

    if (count == 0)
        cout<<"PREDAJA"; 
}