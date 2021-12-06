#include <bits/stdc++.h>
using namespace std; 

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    
    int n; cin>>n; 
    vector<pair<int,int>> wh;

    for(int i=0; i<n; i++)
    {
        int x, y; cin>>x>>y;

        wh.push_back({x, y});
    }

    for(int i=0; i<n; i++)
    {
        int grade = n;

        for(int j=0; j<n; j++)
        {
            if (i == j) continue;

            if (wh[i].first >= wh[j].first || wh[i].second >= wh[j].second)
                grade--;
        }

        cout<<grade<<" ";
    }
}