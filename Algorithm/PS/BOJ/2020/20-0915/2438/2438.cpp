#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int star;
    cin>>star;

    for(int i=0; i<star; i++, cout<<"\n")
    {
        for(int j=0; j<i+1; j++)
        {
            cout<<"*";
        }
    }
}