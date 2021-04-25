#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int t;
    cin>>t;  

    for(int i=0; i<t; i++)
    {
        int st;
        cin>>st;
        
        int tc = 0;
        float tg = 0; 

        for(int j=0; j<st; j++)
        {
            int c;
            float g;
            cin>>c>>g;

            tc += c;
            tg += (c*g);
        } 

        cout<<tc<<" "<<round(tg/tc * 10)/10.0<<"\n";
    }    
}