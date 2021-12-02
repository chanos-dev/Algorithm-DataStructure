#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d[9] = {0,};
    
    int sum = 0;

    for(int i=0; i<9; i++)
    {
        int n; cin>>n;
        d[i] = n;  

        sum += n;
    }    

    int c = sum - 100;

    for(int i=0; i<9; i++)
    {
        for(int j=i+1; j<9; j++)
        {
             if (d[i] + d[j] == c)
             {
                 for(int k=0; k<9; k++)                 
                 {
                     if (d[k] == d[i] || d[k] == d[j])
                        continue;
                     cout<<d[k]<<"\n";
                 }
                 return 0;
             }
        } 
    }
}