#include <bits/stdc++.h>
using namespace std;

int compare(int a, int b)
{
    return a > b;
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    
    int n; cin>>n;
    int* A = new int[n]();
    int* B = new int[n]();

    for(int i=0; i<n; i++)
    {
        int d; cin>>d;
        A[i] = d;
    }

    for(int i=0; i<n; i++)
    {
        int d; cin>>d;
        B[i] = d;
    }


    sort(A, A+n);
    sort(B, B+n, compare);

    int s=0;  
    for(int i=0; i<n; i++)
    {
        s += A[i] * B[i];
    }

    cout<<s;
        
    delete(A);
    delete(B);
}