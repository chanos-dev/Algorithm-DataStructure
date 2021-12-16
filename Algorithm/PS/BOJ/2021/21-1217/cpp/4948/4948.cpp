#include<bits/stdc++.h>
using namespace std; 

bool prime(int n)
{
    if (n < 2) return false;

    for(int i=2; i*i<=n; i++)
    {
        if (n % i == 0) return false;
    }

    return true;
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;
    while(cin>>n)
    { 
        if (n == 0)
            break;

        int cnt = 0;

        for(int i=n+1; i<=n*2; i++)
        {
            if (prime(i))
                cnt++;
        }

        cout<<cnt<<"\n";
    }
}