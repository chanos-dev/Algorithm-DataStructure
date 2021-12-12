#include <bits/stdc++.h>
using namespace std;

vector<string> ages[200];

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; cin>>n;

    for(int i=0; i<n; i++)
    {
        int a; string s; cin>>a>>s;
        ages[a-1].push_back(s);
    }

    for(int i=0; i<200; i++)
    {
        if (ages[i].empty()) continue;

        for(int j=0; j<ages[i].size(); j++)
            cout<<i+1<<" "<<ages[i][j]<<"\n";
    }
}