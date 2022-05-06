#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int t; cin>>t;     
    while(t--)
    {
        int count[10] = {0};
        deque<pair<int, bool>> deq;

        int n, m; cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            int v; cin>>v;
            count[v]++;
            deq.push_back({v, i == m ? true : false});
        }
        
        int cnt = 0;
        for(int i=9;i>=0;i--)
        {
            while(count[i])
            { 
                pair<int, bool> f = deq.front();
                deq.pop_front();
                if (f.first < i) 
                    deq.push_back(f);                 
                else
                {          
                    cnt++; count[i]--;
                    if(f.second) cout<<cnt<<"\n";             
                }
            }
        } 
    }
} 