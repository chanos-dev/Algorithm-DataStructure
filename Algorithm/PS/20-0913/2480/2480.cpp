#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,c;

    cin>>a>>b>>c; 

    if( (a==b) && (b==c) )
    {
        cout<<10000+(a*1000);
    }
    else if( ( (a==b) && (b!=c) || (a==c) && (b!=c) ) )
    {
        cout<<1000+(a*100);
    }
    else if( (b==c) && (a!=c) )
    {
        cout<<1000+(b*100);
    } 
    else
    {
        int max = a > b ? (a > c ? a : c) : (b > c ? b : c);
        cout<<max*100;
    } 
}