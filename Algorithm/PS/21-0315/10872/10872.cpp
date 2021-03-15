#include <bits/stdc++.h>
using namespace std;

int Factorial(int i)
{
    if (i < 2)
        return 1;
    else
        return i * Factorial(i - 1);
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    
    int n;
    cin>>n;
    
    cout<<Factorial(n);
}