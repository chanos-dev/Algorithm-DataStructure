#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    int a,b;
    cin>>a>>b;
    if(a>b) cout<<">";
    else if(a<b) cout<<"<";
    else cout<<"==";
}