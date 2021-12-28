#include <bits/stdc++.h>
using namespace std;

bool vist[100001];

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n, k; cin>>n>>k;

    vector<int> vec;
    queue<pair<int, int>> q;

    q.push({n, 0});
    
    while(!q.empty())
    {
        pair<int, int> p = q.front(); 
        q.pop();
        
        if (p.first == k)
        { 
            vec.push_back(p.second);
        }

        vist[p.first] = true;
        
        if (p.first + 1 < 100001 && !vist[p.first + 1])
            q.push({p.first + 1, p.second + 1});
        if (p.first - 1 >= 0 && !vist[p.first - 1])
            q.push({p.first - 1, p.second + 1});
        if (p.first * 2 < 100001 && !vist[p.first * 2])
            q.push({p.first * 2, p.second + 1});
    }

    sort(vec.begin(), vec.end());     

    int cnt = 0;
    int first = vec[0];

    for(int v : vec)
    {
        if (v == first) cnt ++;
        else  break; 
    }    

    cout<<vec[0]<<"\n"; 
    cout<<cnt;
}