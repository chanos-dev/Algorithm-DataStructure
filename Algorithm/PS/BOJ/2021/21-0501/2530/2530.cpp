#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int h, m, s;
    int is;

    cin>>h>>m>>s;
    cin>>is;

    s += (h * 3600) + (m * 60) + is;

    h = s / 3600;
    if (h>=24) h %= 24;
    m = s % 3600 / 60;
    s = s % 3600 % 60;

    cout<<h<<" "<<m<<" "<<s;
}