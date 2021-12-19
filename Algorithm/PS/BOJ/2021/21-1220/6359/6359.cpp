#include <bits/stdc++.h>
using namespace std; 

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int t; cin>>t;

    for(int i=0; i<t; i++)
    {
        int r; cin>>r;
        vector<bool> room(r+1, false);

        for(int j=1; j<=r; j++)
        {
            for(int k=j; k<=r; k++)
            {
                if (k % j == 0)
                    room[k] = !room[k];
            }
        }

        int cnt = 0;
        for(int j=1; j<=r; j++)
        {
            if (room[j]) cnt++;
        }

        cout<<cnt<<"\n";
    }
}