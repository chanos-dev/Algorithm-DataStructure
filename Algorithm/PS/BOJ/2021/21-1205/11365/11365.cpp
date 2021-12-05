#include <bits/stdc++.h>
using namespace std;  

int main()
{
    while(true)
    {
        string s; getline(cin, s);

        if (s == "END")
            break;

        reverse(s.begin(), s.end());
        cout<<s<<"\n";
    }
}