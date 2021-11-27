#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m; int n;

    int sum = 0; int min = -1; 

    cin>>m>>n;

    for (int i = m; i<=n; i++)
    {
        double s = sqrt(i);

        if (s - (int)s != 0)
            continue;

        sum += i; 

        if (min == -1)
            min = i;
    }

    if (sum == 0)
        cout<<"-1";
    else
        cout<<sum<<"\n"<<min;
} 