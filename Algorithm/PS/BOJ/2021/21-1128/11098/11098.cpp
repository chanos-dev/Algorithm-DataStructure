#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin>>n;

    for (int i=0; i<n; i++)
    {
        int p;

        cin>>p;

        int maxp = -1;
        string player;

        for (int j=0; j<p; j++)
        {
            int p;
            string c;

            cin>>p;
            cin>>c;

            if (maxp <= p)
            {
                maxp = p;
                player = c;
            }
        }

        cout<<player<<"\n";
    }
}