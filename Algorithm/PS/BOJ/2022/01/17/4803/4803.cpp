#include<bits/stdc++.h>
using namespace std;

vector<int> node[501];        
bool vist[501];

int check(int i, int d)
{
    if (d > 0 && node[i].size() > 1)
    {
        int cnt = 0;
        for(int c : node[i])
        {
            if (vist[c]) cnt++;            
        }    

        if (cnt > 1)
            return -1;
    }

    for(int c : node[i])
    {
        if (vist[c]) continue;
        vist[c] = true;
        if (check(c, d+1) == -1) 
            return -1;
    }

    return 1;
}

int main()
{
    int c = 0;
    while(true)
    { 
        int n, m; cin>>n>>m;
        if (n+m == 0) break; 
        for(int i=1; i<=n; i++)
        {
            node[i].clear();
            vist[i] = false;
        }

        for(int i=0; i<m; i++)
        {
            int a, b; cin>>a>>b;

            node[a].push_back(b);
            node[b].push_back(a);
        }

        int t = 0;
        for(int i=1; i<=n; i++)
        {
            if (vist[i]) continue;
            bool already = false;
            for(int c : node[i])
            {
                if (vist[c]) 
                {
                    already = true;
                    break;
                }                
            }
            if (already) continue;

            vist[i] = true;
            if (check(i, 0) == 1)
                t++;
        }

        cout<<"Case "<<++c<<": ";

        if (t == 0)
            cout<<"No trees.\n";
        else if (t==1)
            cout<<"There is one tree.\n";
        else
            cout<<"A forest of "<<t<<" trees.\n";
    }
}