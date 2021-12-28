#include <bits/stdc++.h>
using namespace std;

bool vist[100001];

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n, k; cin>>n>>k;

    queue<pair<int, int>> q;

    q.push({n, 0});
    
    while(!q.empty())
    {
        pair<int, int> p = q.front(); q.pop();

        if (p.first > 100001 || p.first < 0) continue;

        if (p.first == k)
        {
            cout<<p.second;
            return 0;
        }

        if (vist[p.first]) continue;  
        vist[p.first] = true;

        q.push({p.first + 1, p.second + 1});
        q.push({p.first - 1, p.second + 1});
        q.push({p.first * 2, p.second + 1});
    }
}