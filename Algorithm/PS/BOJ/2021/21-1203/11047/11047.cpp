#include <bits/stdc++.h>
using namespace std; 

int main()
{
    int n, k; cin>>n>>k;
    int* A = new int[n];

    for(int i=0; i<n; i++)
    {
        int n; cin>>n;
        A[i] = n;
    }

    int cnt = 0;

    for(int i=n-1; i>=0; i--)
    {
        if (k / A[i] != 0)
        {
            cnt += k / A[i];
            k -= A[i] * (k / A[i]); 
        }    
    }

    cout<<cnt;
}