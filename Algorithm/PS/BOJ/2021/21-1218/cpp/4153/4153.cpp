
#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int t[3];
    while(true)
    {
        cin>>t[0]>>t[1]>>t[2];

        if(t[0]+t[1]+t[2] < 1)
            break; 

        sort(t, t+3);

        if (pow(t[0], 2) + pow(t[1], 2) == pow(t[2], 2))
            cout<<"right\n";
        else
            cout<<"wrong\n";
    }
}