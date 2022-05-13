#include <bits/stdc++.h>
using namespace std; 

vector<pair<int, int>> node[1'005];
bool vist[1'005];

void distance(int s, int t, int d)
{
    if (s == t)
    {
        cout<<d<<"\n";
        return;
    }

    for(pair<int, int> c : node[s])
    {
        if (vist[c.first]) continue;
        vist[c.first] = true;
        
        distance(c.first, t, d + c.second);
    }
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    int n, m; cin>>n>>m;
    for(int i=0; i<n-1; i++)
    {
        int a,b,c; cin>>a>>b>>c;
        node[a].push_back({b, c});
        node[b].push_back({a, c});
    }

    while(m--)
    {
        int s, t; cin>>s>>t;        
        fill_n(vist, n+1, false);
        vist[s] = true;
        distance(s, t, 0);
    }
}

// #include <bits/stdc++.h>
// using namespace std; 

// vector<pair<int, int>> node[1'005];
// bool vist[1'005];

// void distance(int s, int t)
// {
//     queue<pair<int ,int>> q;
//     q.push({s, 0});

//     while(!q.empty())
//     {
//         pair<int, int> p = q.front(); q.pop();
//         if (p.first == t)
//         {
//             cout<<p.second<<"\n";
//             return;
//         }

//         for(pair<int, int> c : node[p.first])
//         {
//             if (vist[c.first]) continue;
//             vist[c.first] = true;

//             q.push({c.first, p.second + c.second});
//         }
//     }
// }

// int main()
// { 
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);  
//     int n, m; cin>>n>>m;
//     for(int i=0; i<n-1; i++)
//     {
//         int a,b,c; cin>>a>>b>>c;
//         node[a].push_back({b, c});
//         node[b].push_back({a, c});
//     }

//     while(m--)
//     {
//         int s, t; cin>>s>>t;

//         fill_n(vist, n+1, false);
//         distance(s, t);
//     }
// }