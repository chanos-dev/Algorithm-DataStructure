#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int year;
    cin>>year;
    bool isleap = (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
     
    cout<<isleap ? "1":"0";
}