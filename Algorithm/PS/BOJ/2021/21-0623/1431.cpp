#include <bits/stdc++.h>
using namespace std;

int GetNumber(string s)
{
    int sum = 0;

    for(int i=0; i<s.length(); i++)
    {
        int n = s[i] - '0';

        if (n >= 0 && n <= 9)
        {
            sum += n;
        }
    }

    return sum;
}

bool Compare(string a, string b)
{
    if (a.length() < b.length())
        return true;
    else if (a.length() > b.length())
        return false; 
    else
    {
        int an = GetNumber(a);
        int bn = GetNumber(b);

        if (an != bn)
            return an < bn;
        else
            return a < b;
    }
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;
    string a[1001];

    cin >> n;

    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    sort(a, a+n, Compare);

    for (int i=0; i<n; i++)
    {
        cout<<a[i]<<"\n";
    }
}