#include <bits/stdc++.h>
using namespace std; 

int GCD(int a, int b)
{
    int tf = a;
    int ts = b;
    int t = 0;

    while(ts)
    {
        t = tf % ts;
        tf = ts;
        ts = t;
    } 

    return tf;
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    
    int n; cin>>n;
    
    for(int i=0; i<n; i++)
    {
        int a,b; cin>>a>>b;
        cout<<(long long int)a*b/GCD(a, b)<<"\n";
    }
}