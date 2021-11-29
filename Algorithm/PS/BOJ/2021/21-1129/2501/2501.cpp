#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vector;

    int n, k;

    cin>>n>>k;

    for(int i=1; i<=n; i++)
    {
        if (n % i == 0)
            vector.push_back(i);
    }

    if (vector.size() == 0)
    {
        cout<<"0";
    }
    else if (vector.size() < k)
    {
        cout<<"0";
    }
    else
    {
        cout<<vector[k-1];
    }
}