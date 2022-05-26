#include <bits/stdc++.h>
using namespace std;  

string line(int n)
{
    if (n < 2) return "-";
    else
    { 
        int d = n / 3;
        string s;
        for(int i=0; i<d; i++)
            s += " ";
        return line(d) + s + line(d);
    }
}

int main()
{    
    int n;
    while (cin >>n)
        cout<<line(pow(3, n))<<"\n";
}