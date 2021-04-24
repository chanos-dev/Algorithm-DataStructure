#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int star;
    cin>>star;

    int des = 0;

    for(int i=0; i<star*2-1; i++, cout<<"\n")
    { 
        (i<star) ? des = i : des--;

        for(int j=0; j<star+des; j++)
        {  
            (star-1-des <= j) ? cout<<"*" : cout<<" ";      
        } 
    }
}