#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;

    cin>>n;

    for(int i=0; i<n; i++, cout<<"\n")
    {
        for(int j=0; j<n; j++)
            cout<<"*";
    }
}