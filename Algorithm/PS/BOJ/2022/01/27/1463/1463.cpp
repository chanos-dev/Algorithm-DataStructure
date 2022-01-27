#include<bits/stdc++.h>
using namespace std;

int one[1000001]; 

int main()
{
    int k; cin>>k;

    one[1] = 0;    

    for(int i=2; i<=k; i++)
    {
        one[i] = one[i-1]+1; 
        if (i%3 == 0)
        {
            one[i] = min(one[i], one[i/3]+1);
        }
        if (i%2 == 0)
        {
            one[i] = min(one[i], one[i/2]+1);
        }
    }

    cout<<one[k];
}