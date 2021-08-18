#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; 
    vector<int> v;    
    cin >> n; 

    for(int i=1; i<=n; i++)
    {
        int x; 
        cin>>x;        
        v.push_back(x);         
    }    

    vector<char> p;
    stack<int> stk;
    int v_idx = 0; 

    for(int i=1; i<=n; i++)
    {    
        stk.push(i);
        p.push_back('+');            

        if (!stk.empty())
        {  
            while(v[v_idx] == stk.top())
            {
                stk.pop();
                p.push_back('-');
                v_idx++;

                if (stk.empty() || v_idx > n) break;
            }
        }
    }   

    if (stk.empty())
    {
        for(auto c : p)
            cout<<c<<"\n";
    }
    else
    {
        cout<<"NO";
    }    
}