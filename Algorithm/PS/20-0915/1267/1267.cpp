#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    int Y = 0, M = 0;

    cin>>n;

    for(int i=0; i<n; i++)
    {
        int price;
        cin>>price;

        Y += (price/30)*10+10; 
        
        M += (price/60)*15+15; 
    }

    if(Y == M)
        cout<<"Y M "<<Y;
    else if(Y < M)
        cout<<"Y "<<Y;
    else
        cout<<"M "<<M;
}