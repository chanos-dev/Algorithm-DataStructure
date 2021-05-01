#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int h, m;
    int im;

    cin>>h>>m;
    cin>>im;

    m += (h * 60) + im;

    h = m / 60;
    if (h >= 24) h -= 24;
    m = m % 60;

    cout<<h<<" "<<m;
}