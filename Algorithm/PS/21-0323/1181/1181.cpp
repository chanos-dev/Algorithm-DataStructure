#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;
    cin>>n;

    cin.ignore(256, '\n');

    list<pair<int, string>> strs;

    for(int i=0; i<n; i++)
    {
        string str;
        getline(cin,str); 
 
        strs.push_back({str.length(), str});
    }

    strs.sort(); 
    strs.erase(unique(strs.begin(), strs.end()), strs.end());
    for(auto e : strs)
    {
        cout<<e.second<<"\n";
    }
}