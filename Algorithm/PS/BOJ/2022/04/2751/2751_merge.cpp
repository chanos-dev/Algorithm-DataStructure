#include <bits/stdc++.h>
using namespace std;

int A[1000000];
int n;

void merge(int s, int m, int e)
{
    int sorted[n];

    int l=s;
    int r=m+1;
    int k=0;

    while(l <= m && r <= e)
    {
        if (A[l] < A[r])
            sorted[k++] = A[l++];
        else
            sorted[k++] = A[r++];
    }

    while(l <= m)
        sorted[k++] = A[l++];

    while(r <= e)
        sorted[k++] = A[r++];
    
    while(k >= 0)
    {
        k--;
        A[s+k] = sorted[k];    
    }
}

void mergeSort(int s, int e)
{
    if (s > e) return;

    int m = (s+e)/2;

    mergeSort(s, m);
    mergeSort(m+1, e);
    merge(s, m, e);
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>A[i];
    
    sort(A, A+n);

    for(int i=0; i<n; i++)
        cout<<A[i]<<"\n";        
} 