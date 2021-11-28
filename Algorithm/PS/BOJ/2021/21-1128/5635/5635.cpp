#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; 

    cin >> n;

    string minA = "10000101";
    string minName;

    string maxA = "29991231";
    string maxName;
    
    for (int i=0; i<n; i++)
    {
        string name;
        string d;
        string m;
        string y;

        cin>>name>>d>>m>>y;

        if (m.length() < 2)
            m = "0"+m;
        
        if (d.length() < 2)
            d = "0"+d;

        if (y+m+d >= minA)
        {
            minA = y+m+d;
            minName = name;
        }

        if (y+m+d <= maxA)
        {
            maxA = y+m+d;
            maxName = name;
        }
    }

    cout<<minName<<"\n"<<maxName;
} 