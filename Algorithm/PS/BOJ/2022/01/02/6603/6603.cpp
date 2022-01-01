#include<bits/stdc++.h>
using namespace std;

vector<int> lo;
int co[6];
bool used[50];

void lotto(int k)
{ 
    if (k == 6)
    {
        for(int i=0; i<k; i++)
            cout<<co[i]<<" ";
        cout<<"\n";
        return;
    }

    for(int i=0; i<lo.size(); i++)
    {
        if (!used[lo[i]])
        {
            if (k > 0)
            {
                if (co[k-1] > lo[i])
                    continue;
            }

            co[k] = lo[i];
            used[lo[i]] = true;
            lotto(k+1);
            used[lo[i]] = false;
        } 
    } 
}

int main()
{
    while(true)
    {
        int n; cin>>n;

        if (n == 0) break;

        for(int i=0; i<n; i++)
        {
            int v; cin>>v;
            lo.push_back(v);
        }

        lotto(0); 
        lo.clear();
        cout<<"\n";
    }
}
// 7 1 2 3 4 5 6 7