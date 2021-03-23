#include <bits/stdc++.h>
using namespace std;
#define day 86400;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int h, m, s;
    int tc;
    int time = 0;

    cin>>h>>m>>s>>tc;

    time = h*3600 + m*60 + s; 

    for(int i=0; i<tc; i++)
    {
        int t, c;
        cin>>t;

        if (t==1)
        {
            cin>>c;

            time = (time + c) % day;
        }
        else if (t==2)
        {
            cin>>c;

            time = (time - c) % day; 

            if (time < 0)
                time += day;
        }
        else
        {  
            h = time / 3600;
            m = (time / 60) % 60;
            s = time % 60;

            cout<<h<<" "<<m<<" "<<s<<"\n";
        } 
    }
}