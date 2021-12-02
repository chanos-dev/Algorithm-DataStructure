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

    if (v.size() != 1)
        cout<<v[0]*v[v.size()-1];
    else 
        cout<<v[0]*v[0];
}