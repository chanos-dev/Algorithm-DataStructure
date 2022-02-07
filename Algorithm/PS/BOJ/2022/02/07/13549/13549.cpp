#include <bits/stdc++.h>
using namespace std;

bool vist[200001];

int main()
{ 
    int n, k; cin>>n>>k;

    queue<pair<int, int>> q;
    int ans = 999999;
    q.push({n, 0});
    while(!q.empty())
    {
        pair<int, int> p = q.front(); 
        q.pop();  

        vist[p.first] = true;
        
        if (p.first == k)
        {
            ans = min(ans,p.second);
            continue;
        }
 
        if (p.first < 100001 && !vist[p.first*2])
            q.push({p.first * 2, p.second});
        if (p.first < 100001 && !vist[p.first+1])
            q.push({p.first + 1, p.second + 1});
        if (p.first > 0 && !vist[p.first-1])
            q.push({p.first - 1, p.second + 1}); 
    }

    cout<<ans;
}