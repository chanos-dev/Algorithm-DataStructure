// 53퍼 시간초과
#include <bits/stdc++.h>
using namespace std;

int N[500001];
int n; 

int LeftBinarySearch(int s, int e, int target)
{  
    while(true)
    {
        if (s > e) return 0;

        int mid = (s + e) / 2;
        if (N[mid] < target) 
            s = mid + 1;
        else if (N[mid] > target)
            e = mid - 1;
        else
        {
            if (mid > 0)
            {
                if (N[mid-1] == target)
                    e = mid - 1;
                else
                    return mid;
            }
            else return 0;
        }
    }  
}

int RightBinarySearch(int s, int e, int target)
{  
    while(true)
    {
        if (s > e) return 0;

        int mid = (s + e) / 2;
        if (N[mid] < target) 
            s = mid + 1;
        else if (N[mid] > target)
            e = mid - 1;
        else
        {
            if (mid < n-1)
            {
                if (N[mid+1] == target)
                    s = mid + 1;
                else
                    return mid + 1;
            }
            else return n;
        }
    }  
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>N[i];
    sort(N, N+n);
    int m; cin>>m;
    for(int i=0; i<m; i++)
    {
        int t; cin>>t; 
        cout<<RightBinarySearch(0, n-1, t) - LeftBinarySearch(0, n-1, t)<<" ";        
    }
}