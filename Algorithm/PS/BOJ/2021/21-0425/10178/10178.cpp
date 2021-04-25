#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int c,v;
        cin>>c>>v;

        cout<<"You get "<<c/v<<" piece(s) and your dad gets "<<c%v<<" piece(s).\n";
    }
}