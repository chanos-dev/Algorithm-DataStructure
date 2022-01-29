#include<bits/stdc++.h>
using namespace std;

vector<int> node[50001];
bool vist[50001];
int ans_max;
int ans_min = 60000;
vector<int> ans;

void sol(int i)
{
    queue<pair<int, int>> q;
    q.push({i, 0});
    vist[i] = true;

    while(!q.empty())
    {
        int n = q.front().first;
        int k = q.front().second;        
        q.pop(); 

        if (ans_max < k)
        {
            ans.clear();
            ans_max = k;
            ans_min = 60000;
        }

        if (ans_max == k)
        { 
            if (ans_min > n)
                ans_min = n;

            ans_max = k;
            ans.push_back(n);
        }

        for(int c : node[n])
        {
            if (vist[c]) continue;
            vist[c] = true; 

            q.push({c, k+1});
        }
    }
}

int main()
{
    int n, m;

    cin>>n>>m;

    while(m--)
    {
        int a, b; cin>>a>>b;

        node[a].push_back(b);
        node[b].push_back(a);
    }

    sol(1);

    cout<<ans_min<<" "<<ans_max<<" "<<ans.size();
}