#include <bits/stdc++.h>
using namespace std;

#define pi 3.141592;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int d1, d2;

    cin>>d1>>d2;

    double r = d1*2 + d2*2*pi;
    cout.precision(12);
    cout<<r;
}