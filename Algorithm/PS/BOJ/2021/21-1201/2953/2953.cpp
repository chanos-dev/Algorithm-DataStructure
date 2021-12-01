#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    int max = 0;
    int idx = -1;    

    for(int i=0; i<5; i++)
    {
        int ts = 0;

        for(int j=0; j<4; j++)
        {
            int s;
            cin>>s;

            ts += s;
        }

        if (ts > max)
        {
            max = ts;
            idx = i+1;
        }
    }    

    cout<<idx<<" "<<max;
}