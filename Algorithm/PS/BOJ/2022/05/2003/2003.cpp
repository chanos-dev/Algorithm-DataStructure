#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n, m;
    cin>>n>>m;

    int A[10'005];
    for(int i=0; i<n; i++)
        cin>>A[i];
    
    int e = 0;
    int sum = 0;
    int ans = 0;

    for(int s=0; s<n; s++)
    {
        while(e < n && sum < m)
            sum += A[e++];            
        
        if (sum == m)
            ans++;
            
        sum -= A[s];
    }

    cout<<ans;
}