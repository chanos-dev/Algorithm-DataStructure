#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    int h,m;
    cin>>h>>m;

    m-=45;
    if(m<0)
    {
        if(h==0)
            h = 23;
        else 
            h -= 1;
        
        m += 60;
    }

    cout<<h<<" "<<m;
}