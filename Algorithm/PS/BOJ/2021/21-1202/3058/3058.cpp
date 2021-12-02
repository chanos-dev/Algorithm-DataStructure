#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;

    for(int i=0; i<n; i++)
    {
        int sum = 0;
        int mv = 101;

        for(int j=0; j<7; j++)
        {
            int v; cin>>v;

            if (v % 2 == 0)
            {
                sum += v;

                if (mv >= v)
                {
                    mv = v;
                }
            }
        }

        cout<<sum<<" "<<mv<<"\n";
    }
}