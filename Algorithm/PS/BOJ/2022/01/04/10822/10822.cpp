#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin>>s;

    int sum = 0;
    string n;

    for(char c : s)
    {
        if (c != ',')
        {
            n += c;
        }
        else
        { 
            sum += stoi(n);
            n = ""; 
        }
    }

    if (n != "") sum += stoi(n);

    cout<<sum;
}