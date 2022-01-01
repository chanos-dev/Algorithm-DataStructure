#include<bits/stdc++.h>
using namespace std;

int z(int n, int r, int c)
{
    if (n == 0) return 0;

    int half = 1<<(n-1);

    //1 
    if (r < half && c < half)
        return z(n-1, r, c);
    //2 
    if (r < half && c >= half)
        return half*half + z(n-1, r, c-half);
    //3 
    if (r >= half && c < half)
        return 2 * half*half + z(n-1, r-half, c);
    //4 
    return 3 * half*half + z(n-1, r-half, c-half); 
     
}

int main()
{
    int n, r, c; cin>>n>>r>>c;
    cout<<z(n,r,c);
}