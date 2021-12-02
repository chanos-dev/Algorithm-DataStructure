#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int n; cin>>n;
    vector<int> v;

    for(int i=0; i<n; i++)
    {
        int nv; cin>>nv;
        v.push_back(nv);
    }

    sort(v.begin(), v.end());

    for(int vi : v)
    {
        cout<<vi<<"\n";
    }
}