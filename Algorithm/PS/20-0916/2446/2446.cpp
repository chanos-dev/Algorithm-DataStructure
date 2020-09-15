#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int star;
    cin>>star; 

    int des = star*2-1, space = 0;

    for(int i=0; i<star*2-1; i++, cout<<"\n")
    {  
        for(int j=0; j<des; j++)
        {   
            (space <= j) ? cout<<"*" : cout<<" ";
        }  

        if(i < star-1)
        {
            des--; 
            space++;
        }
        else
        {
            des++;
            space--;
        }
    }
}