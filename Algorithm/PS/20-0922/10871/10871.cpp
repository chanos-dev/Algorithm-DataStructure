#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    int n, x;

    cin>>n>>x; 
    while(n--)
    {
        int n;
        cin>>n;
        if(n < x) cout<<n<<" ";
    } 
}