#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    int S[30] = {0,};

    for(int i=0; i<28; i++)
    {
        int n; cin>>n;
        S[n-1]++;
    }

    for(int i=0; i<30; i++)
    {
        if (S[i] == 0)
            cout<<i+1<<"\n";
    }
}