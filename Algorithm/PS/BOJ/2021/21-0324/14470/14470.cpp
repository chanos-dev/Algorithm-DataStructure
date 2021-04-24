#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    int A, B, C, D, E;
    int sec = 0;

    cin>>A>>B>>C>>D>>E;
    sec = (A <= 0) ? (-A*C)+(B*E) + D : abs(B-A)*E;
    cout<<sec;
}