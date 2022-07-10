#include <bits/stdc++.h>
using namespace std;

int coins[1001];
vector<pair<int, int>> dcs[1001]; 
int ans = 999999999;
int bought[10];
bool used[10];
int N;

void buy(int k)
{
    if (k == N)
    {
        int s = 0;
        for(int i=0; i<N; i++)
        {
            int c = bought[i];
            if (c < 1)
                c = 1;
            s += c;
        }
        if (s < ans)
            ans = s;
        return;
    }

    for (int i=0; i<N; i++)
    {
        if (!used[i])
        {
            bought[k] = coins[i];

            for(pair<int, int> dc : dcs[i]) 
                coins[dc.first-1] -= dc.second; 
            used[i] = true;

            buy(k+1);
            
            for(pair<int, int> dc : dcs[i]) 
                coins[dc.first-1] += dc.second; 
            used[i] = false;
        }
    }
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    cin>>N; 
    for(int i=0; i<N; i++) 
        cin>>coins[i];  

    for(int i=0; i<N; i++)
    {
        int p; cin>>p;
        for(int j=0; j<p; j++)
        {
            int n, c; cin>>n>>c;
            dcs[i].push_back({n, c});
        } 
    } 

    buy(0);

    cout<<ans;
}