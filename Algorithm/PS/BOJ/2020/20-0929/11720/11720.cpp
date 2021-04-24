#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;
    int sum = 0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        char a;
        cin>>a;
        sum += a - '0';
    }

    cout<<sum;
}