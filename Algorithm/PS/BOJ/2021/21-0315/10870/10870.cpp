#include <bits/stdc++.h>
using namespace std;

int Fibo(int n)
{
    if (n == 0)
        return 0;

    if (n > 2)
        return Fibo(n-1) + Fibo(n-2);
    else
        return 1;  
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;
    cin>>n;

    cout<<Fibo(n);
}