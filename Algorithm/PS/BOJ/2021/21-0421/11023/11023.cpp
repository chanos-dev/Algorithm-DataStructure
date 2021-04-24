#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int sum = 0;
    int n;
    while(true)
    {
        cin>>n;
        if(cin.eof()) break;
        sum += n;
    }

    cout<<sum;
}