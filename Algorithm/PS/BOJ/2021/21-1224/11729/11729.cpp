#include<bits/stdc++.h>
using namespace std;

void hanoi(int from, int mid, int to, int n)
{
    if (n == 1) 
    {
        cout<<from<<" "<<to<<"\n";    
        return;
    }

    hanoi(from, to, mid, n-1);
    cout<<from<<" "<<to<<"\n";
    hanoi(mid, from, to, n-1);
}

int main()
{
    int n; cin>>n;
    // 2^n-1
    int cnt = 2;
    for(int i=0; i<n-1; i++)
        cnt = cnt * 2;
    cout<<cnt-1<<"\n";
    hanoi(1, 2, 3, n);    
}