#include<bits/stdc++.h>
using namespace std;

vector<int> chon[101];
bool vist[101];
int p1, p2; 
bool isfind = false;

void check(int i, int ans)
{
    if (i == p2)
    {
        cout<<ans;
        isfind = true;
        return;
    }

    for(int c : chon[i])
    { 
        if (vist[c]) continue;
        vist[c] = true;

        check(c, ans+1);
    }
}

int main()
{
    int n; cin>>n; 
    cin>>p1>>p2;
    int t; cin>>t;

    while(t--)
    {
        int p, c; cin>>p>>c;

        chon[p].push_back(c);
        chon[c].push_back(p);
    }

    vist[p1] = true;
    check(p1, 0);

    if (!isfind)
        cout<<"-1";
}  