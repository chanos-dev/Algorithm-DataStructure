#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int count;
    cin>>count;
    for(int i=0; i<count; i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<"Case #"<<i+1<<": "<<a<<" + "<<b<<" = "<<a+b<<"\n";
    }
}