#include <bits/stdc++.h>
using namespace std;

int A[1000001]; 
int B[1000001];

int FindTwoTarget(int s, int e, int target)
{
    if (abs(s-e) <= 1)
    {        
        if (abs(B[s]-target) < abs(B[e]-target)) return B[s];
        else if (abs(B[s]-target) > abs(B[e]-target)) return B[e];
        else return min(B[s], B[e]);
    }

    int mid = (s+e)/2;
    if (B[mid] < target) 
        return FindTwoTarget(mid, e, target);
    else if (B[mid] > target)
        return FindTwoTarget(s, mid, target); 
    else
        return B[mid];
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m; 

        for(int i=0; i<n; i++)
            cin>>A[i];
            
        for(int i=0; i<m; i++)
            cin>>B[i];

        sort(B, B+m);      
        long long sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += FindTwoTarget(0, m-1, A[i]);
        }

        cout<<sum<<"\n";
    }
}