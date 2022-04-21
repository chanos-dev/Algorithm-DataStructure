#include <bits/stdc++.h>
using namespace std;

int A[100001];

int BinarySearch(int s, int e, int target)
{ 
    if (s > e)
        return 0;

    int mid = (s+e)/2;
    if (A[mid] < target) 
        return BinarySearch(mid+1, e, target);
    else if (A[mid] > target)
        return BinarySearch(s, mid-1, target); 
    else
        return 1;
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; cin>>n;
    for(int i=0; i<n; i++)
        cin>>A[i];    
    sort(A, A+n);

    int m; cin>>m;
    for(int i=0; i<m; i++)
    {
        int t; cin>>t;
        cout<<BinarySearch(0, n-1, t)<<"\n";
    }
}