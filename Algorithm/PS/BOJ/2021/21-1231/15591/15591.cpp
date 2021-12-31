#include <bits/stdc++.h>
using namespace std;

#define n first
#define k second

vector<pair<int, int>> Moo[5001]; 

int main()
{ 
    int N, Q; cin>>N>>Q; 

    for(int i=0; i<N-1; i++)
    {
        int p,q,r; cin>>p>>q>>r;

        Moo[p].push_back({q, r});
        Moo[q].push_back({p, r});
    }

    while(Q--)
    {
        int k, v; cin>>k>>v;

        vector<bool> vist(N+1, false);
        int cnt = 0;

        queue<pair<int, int>> q;
        q.push({v, 1000000001});
        vist[v] = true;

        while(!q.empty())
        {
            pair<int, int> m = q.front(); q.pop();

            for(pair<int, int> p : Moo[m.n])
            { 
                if (vist[p.n]) continue;
                vist[p.n] = true;

                int minK = min(m.k, p.k);

                if (minK >= k)
                    cnt++;
                
                q.push({p.n, minK});
            }
        } 

        cout<<cnt<<"\n";
    }
}