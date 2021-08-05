#include <bits/stdc++.h>
using namespace std; 

int main()
{  
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;
    cin >> n;

    vector<int> v(n), ans(n, -1);
    stack<int> stk;

    for (int i=0;i<n;i++)
    {
        int a;
        cin >> a;

        v[i] = a;
    }

    for (int i=0;i<n;i++)
    {
        while(!stk.empty() && v[stk.top()] < v[i])
        {
            ans[stk.top()] = v[i];            
            stk.pop();
        }

        stk.push(i);
    }

    for (int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";        
    }
}