#include <bits/stdc++.h>
using namespace std;

int main()
{    
    int t; cin>>t;

    for(int i=0; i<t; i++)
    {
        vector<int> v;
        for(int j=0; j<5; j++)
        {
            int n; cin>>n;
            v.push_back(n);
        }

        sort(v.begin(), v.end());

        if (abs(v[1] - v[3]) >= 4)
            cout<<"KIN\n";
        else
            cout<<v[1]+v[2]+v[3]<<"\n";
    }
}