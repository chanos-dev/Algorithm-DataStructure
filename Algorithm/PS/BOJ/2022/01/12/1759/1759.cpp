#include<bits/stdc++.h>
using namespace std;

int l, c;

char ans[16];
set<char> d;
char used[26];

void enc(int k, int m, int j)
{
    if (l == k)
    {
        if (m < 1 || j < 2) return;
        for(int i=0; i<l; i++)
            cout<<ans[i];
        cout<<"\n";
        return;
    }

    for(char a : d)
    {
        int idx = a - 'a';

        if (used[idx]) continue;
        
        if (k > 0 && ans[k-1] > a) continue;

        ans[k] = a;

        used[idx] = true;

        if (a == 'a' ||
            a == 'e' ||
            a == 'i' ||
            a == 'o' ||
            a == 'u')
            enc(k+1,m+1, j);
        else
            enc(k+1,m, j+1);

        used[idx] = false;
    }
}

int main()
{
    cin>>l>>c;

    for(int i=0; i<c; i++)
    {
        char a; cin>>a;
        d.insert(a);
    }

    enc(0, 0, 0);
}