#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    long long int A, B;
    cin>>A>>B;

    (A==B) ? cout<<"0\n" : cout<<abs(A-B)-1<<"\n";

    if(A > B)
    {
        long long int temp = A;
        A = B;
        B = temp;
    }

    for(long long int i=A+1; i<B; i++)
    {
        if(i+1 == B)
            cout<<i;
        else
            cout<<i<<" ";
    } 
}