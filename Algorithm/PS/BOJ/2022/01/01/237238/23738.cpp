#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin>>s;

    for(char C : s)
    {
        char c = C + 32;

        switch(c)
        {
            case 'b':
                cout<<"v";
                break;
            case 'e':
                cout<<"ye";
                break;
            case 'h':
                cout<<"n";
                break;
            case 'p':
                cout<<"r";
                break;
            case 'c':
                cout<<"s";
                break;
            case 'y':
                cout<<"u";
                break;
            case 'x':
                cout<<"h";
                break;
            default:
                cout<<c;
                break;
        }
    }
}