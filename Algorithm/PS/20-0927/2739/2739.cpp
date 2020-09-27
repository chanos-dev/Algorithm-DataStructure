#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;
    cin>>n;
    for(int i=1; i<=9; i++)
    {
        cout<<n<<" * "<<i<<" = "<<n*i<<"\n";
    }
}