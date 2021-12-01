#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    int a, b;
    cin>>a>>b;

    int tcnt = 0;
    int sum = 0;

    for(int i=1; i<=b; i++)
    {
        for(int j=0; j<i; j++)
        {            
            tcnt++;

            if (a <= tcnt && tcnt <= b)
            {
                sum += i;
            } 
        }

        if (tcnt > b)
            break;
    }

    cout<<sum;
}