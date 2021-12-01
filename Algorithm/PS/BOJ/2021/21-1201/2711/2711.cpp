#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin>>n;
    
    for(int i=0; i<n; i++)
    {
        int o; string s;

        cin>>o>>s;

        for(int j=0; j<s.size(); j++)
        {
            if (j+1 != o)
                cout<<s[j];
        }

        cout<<"\n";
    }
}