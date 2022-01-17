#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n,k; cin>>n>>k;

    int cnt = 0;  
    bool f[1001] = {0,};

    for(int i=2; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i)
        {             
            if (f[j]) continue;
            f[j] = true;
            cnt++;

            if (cnt == k)
            {
                cout<<j;
                return 0;
            }
        }
    }
}