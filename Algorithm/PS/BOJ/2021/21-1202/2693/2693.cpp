#include <bits/stdc++.h>
using namespace std;

int main()
{    
    int t; cin>>t;

    for(int i=0; i<t; i++)
    {
        int A[10] = {0,};

        for(int j=0; j<10; j++)
        {
            int n; cin>>n;
            A[j] = n;
        }

        sort(A, A+10);

        cout<<A[10-3]<<"\n";
    }
}