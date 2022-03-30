#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;
    cin>>n;

    int pyramid[n][n];
    int sumPyramid[n][n];    

    for(int i=0; i<n; i++) 
        for(int j=0; j<=i; j++) 
        {
            cin>>pyramid[i][j]; 
            sumPyramid[i][j] = 0;
        }
    
    
    int ans = sumPyramid[0][0] = pyramid[0][0];

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<=i; j++)
        {
            int one = sumPyramid[i][j] + pyramid[i+1][j];
            int two = sumPyramid[i][j] + pyramid[i+1][j+1];

            if (one > sumPyramid[i+1][j])
                sumPyramid[i+1][j] = one;
            
            if (two > sumPyramid[i+1][j+1])
                sumPyramid[i+1][j+1] = two;
            
            ans = max(max(ans, one), two);
        } 
    }

    cout<<ans;
}