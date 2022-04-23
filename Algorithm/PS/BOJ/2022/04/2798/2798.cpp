#include <bits/stdc++.h>
using namespace std;

int jack[101];

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n, m; cin>>n>>m;

    for(int i=0; i<n; i++)
        cin>>jack[i];
    
    int sum = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                int jsum = jack[i] + jack[j] + jack[k];
                if (jsum <= m)
                {
                    if (sum < jsum)
                        sum = jsum;
                }
            }
        }
    }

    cout<<sum;
}