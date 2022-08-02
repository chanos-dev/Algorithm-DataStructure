#include <bits/stdc++.h>
using namespace std;

int one[1000001] = {0, 0, 1, 1, };

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
        
    int x; cin>>x;

    for(int i=4; i<=x; i++)
    {
        one[i] = one[i-1] + 1;

        if (i % 3 == 0)
            one[i] = min(one[i], one[i/3]+1);
        if (i % 2 == 0)
            one[i] = min(one[i], one[i/2]+1);
    }

    cout<<one[x];
}