#include <bits/stdc++.h>
using namespace std;
#define INF 2100000000

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n, S; cin>>n>>S;
    int arr[100'005];

    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int len = INF;    
    int e = 0;
    int sum = arr[e];
    for(int s = 0; s < n; s++)
    {        
        while(e < n && sum < S)
        {
            e++;
            if (e < n) sum += arr[e];
        }
        if (e == n) break;   
        len = min(len, e - s + 1);
        sum -= arr[s];
    }
    if (len == INF) cout<<"0";
    else cout<<len;
}