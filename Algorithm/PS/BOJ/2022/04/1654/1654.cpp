#include <bits/stdc++.h>
using namespace std;

int lan[10001];

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);      
    long long s = 1;
    long long e = 0x7FFFFFFF;
    int k, n;
    cin>>k>>n;
    for(int i=0; i<k; i++)
        cin>>lan[i];
    
    while(s < e)
    {
        long long m = (s+e+1) /2;

        long long c = 0;
        for(int i=0; i<k; i++)
            c += lan[i] / m;

        if (c >= n) s = m;
        else e = m-1;
    }

    cout<<s;
}