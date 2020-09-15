#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int star;
    cin>>star; 

    int begin = 0 , end = star*2-1;

    for(int i=0; i<star*2-1; i++, cout<<"\n")
    {  
        for(int j=0; j<star*2; j++)
        {   
            (j <= begin) || (j >= end) ? cout<<"*" : cout<<" ";            
        } 

        if(i < star-1)
        {
            begin++;
            end--;
        }
        else
        {
            begin--;
            end++;
        }
    }
}