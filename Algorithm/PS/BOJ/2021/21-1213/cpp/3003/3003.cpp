#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c[6] = {1, 1, 2, 2, 2, 8};

    for(int i=0; i<6; i++)
    {
        int n; cin>>n;
        
        cout<<(c[i] - n)<<" ";
    }
}