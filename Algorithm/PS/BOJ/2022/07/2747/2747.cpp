#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int fibo[46] = {0, 1, };

    for(int i = 2; i < 46; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];

    int n; cin>>n;
    cout<<fibo[n];
}