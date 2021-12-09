#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; cin>>n;

    for(int i=0; i<n; i++)
    {
        string s; cin>>s;

        int score = ((s[0]-65) * 26 * 26) + ((s[1]-65) * 26) + s[2]-65; 
        score = abs(score - stoi(s.substr(4, 4))); 
        
        if (score <= 100)
            cout<<"nice\n";
        else
            cout<<"not nice\n";
    }
}