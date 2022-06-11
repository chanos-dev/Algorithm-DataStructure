#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    int t; cin>>t;
    for(int i=0; i<t; i++)
    {
        int k; cin>>k;
        multiset<int> set;
        for(int j=0; j<k; j++)
        {
            char c; int n; cin>>c>>n;

            if (c=='I')
                set.insert(n);
            else
            {
                if (set.empty()) continue;
                if (n > 0) set.erase(prev(set.end()));
                else set.erase(set.begin());
            }            
        }

        if (set.empty()) cout<<"EMPTY\n";
        else cout<<*prev(set.end())<<" "<<*set.begin()<<"\n";
    }
}