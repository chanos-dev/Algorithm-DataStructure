// Two Pointer
#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n, m;
    cin>>n>>m;
    int arr[100005];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    sort(arr, arr+n);

    int e = 0;
    int minV = 2100000000; 

    for(int s=0; s<n; s++)
    {
        if (e == n) break;
        while (arr[e]-arr[s] < m) e++;        
        minV = min(minV, arr[e]-arr[s]);
    }

    cout<<minV;
}


// Binary Search
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// { 
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);  

//     int n, m;
//     cin>>n>>m;
//     int arr[100005];
//     for(int i=0; i<n; i++)
//         cin>>arr[i];
    
//     sort(arr, arr+n);

//     int s = 0;
//     int e = n-1;
//     int minV = 2100000000;
//     for(int i=0; i<n; i++)
//     {
//         int idx = lower_bound(arr, arr+n, arr[i]+m) - arr;

//         if (idx < n)
//             minV = min(minV, arr[idx] - arr[i]);
//     }

//     cout<<minV;
// }