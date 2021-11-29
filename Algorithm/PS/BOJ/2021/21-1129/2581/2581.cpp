#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    int min = 99999;
    int sum = 0;

    cin>>m>>n; 

    for (int i=m; i<=n; i++)
    {
        if (i == 1)
            continue;
            
        bool isPrime = true;
        for (int j=2; j<=i/2; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (!isPrime)
            continue;

        if (min > i)
            min = i;
        
        sum += i;
    }

    if (sum <= 1) 
        cout<<"-1"; 
    else
        cout<<sum<<"\n"<<min;
}