#include <bits/stdc++.h>
using namespace std;  

int main()
{
    int n; cin>>n;

    for(int i=0; i<n; i++)
    {
        string s1, s2; cin>>s1>>s2;

        //Distances: 0 1 2 3
        cout<<"Distances: ";

        for(int j=0; j<s1.length(); j++)
        {
            if (s1[j] <= s2[j])
            {
                cout<<s2[j]-s1[j]<<" ";
            } 
            else
            {
                cout<<(s2[j] + 26) - s1[j]<<" ";
            }
        }

        cout<<"\n";
    } 
}