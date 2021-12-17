#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int t; cin>>t;

    for(int i=0; i<t; i++)
    {
        int h, w, n; cin>>h>>w>>n;

        int y = n % h;
        float x = (float)n / h;
        
        if (y == 0) y = h;
        if (x > (int)x)
            x++;
        
        if (x < 10)
            cout<<y<<"0"<<(int)x<<"\n";
        else
            cout<<y<<(int)x<<"\n";
    }    
}