#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int sum = 0;
    vector<int> v;
    vector<int> s;
    vector<int> a;

    for(int i=0; i<8; i++)
    {
        int n;
        cin>>n;

        v.push_back(n);
        s.push_back(n);
    }

    sort(s.begin(), s.end());

    for(int i=3; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if (s[i] == v[j])
            {
                a.push_back(j+1);
                sum += v[j];
            }
        }
    }
    
    sort(a.begin(), a.end());

    cout<<sum<<"\n";    
    for(int i=0; i<a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
}