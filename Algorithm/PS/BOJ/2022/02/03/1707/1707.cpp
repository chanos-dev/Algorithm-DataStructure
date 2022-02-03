#include<bits/stdc++.h>
using namespace std;

bool group(int v, vector<int> node[])
{
    queue<int> q;
    int color[v] = {0,};
    
    for(int i=1; i<v; i++)
    {
        q.push(i);

        if (color[i] == 0)
            color[i] = 1;

        while(!q.empty())
        {
            int p = q.front(); q.pop();

            for(int c : node[p])
            {
                if (color[c] == 0)
                {
                    color[c] = color[p] * -1;            
                    q.push(c);
                }
                else if (color[c] == color[p])
                    return false;
            } 
        } 
    } 

    return true;
}

int main()
{
    int k; cin>>k;
    while(k--)
    {
        int v,e; cin>>v>>e;
        vector<int> node[v+1];

        for(int i=0; i<e; i++)
        {
            int a,b; cin>>a>>b;

            node[a].push_back(b);
            node[b].push_back(a);
        }

        if (group(v+1, node)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}