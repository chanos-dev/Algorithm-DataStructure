#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n, m;
    cin>>n>>m;
    int tree[n+1];
    for(int i=0; i<n; i++)
        cin>>tree[i];
    int s = 0;
    int e = 1'000'000'000;

    while(s < e)
    {
        int mid = (s+e+1)/2;

        long long c = 0;
        for(int i=0; i<n; i++)
        {
            if (tree[i] / mid > 0)
                c += tree[i] - mid;
        } 
        
        if (c >= m) s = mid;
        else e = mid-1;
    }   

    cout<<s;
}