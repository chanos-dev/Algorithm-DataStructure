#include<bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;

bool usedy[30];
bool usedls[30];
bool usedrs[30];

void queen(int k)
{
    if (k == n)
    {
        cnt++;
        return;
    }

    for(int i=0; i<n; i++)
    {
        if (usedy[i] || usedls[i+k] || usedrs[k-i+n-1]) continue;

        usedrs[k-i+n-1] = usedls[i+k] = usedy[i] = true; 
        queen(k+1);
        usedrs[k-i+n-1] = usedls[i+k] = usedy[i] = false; 
    }
}

int main()
{
    cin>>n;
    queen(0);
    cout<<cnt;
}