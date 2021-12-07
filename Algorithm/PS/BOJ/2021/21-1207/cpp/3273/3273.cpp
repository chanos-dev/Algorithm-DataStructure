#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n, x;
    vector<int> v;

    cin>>n; 

    for(int i=0; i<n; i++) 
    {
        int a; cin>>a;
        v.push_back(a);
    }

    cin>>x; 

    sort(v.begin(), v.end());

    int s = 0;
    int e = v.size()-1;
    int cnt = 0; 

    while(true)
    {
        if (s >= e) break;

        if (x == v[s]+v[e])
        {
            s++;
            e--;
            cnt++;
        }
        else if (v[s]+v[e] > x)
            e--;
        else
            s++;
    }

    cout<<cnt;
}