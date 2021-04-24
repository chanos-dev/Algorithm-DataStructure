#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int star;
    cin>>star;

    for(int i=star-1; i>=0; i--, cout<<"\n")
    {
        for(int j=0; j<star; j++)
        {
            (i<=j) ? cout<<"*" : cout<<" ";
        }
    }
}