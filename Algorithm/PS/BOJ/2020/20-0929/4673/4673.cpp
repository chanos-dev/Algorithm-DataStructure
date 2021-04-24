#include <bits/stdc++.h>
using namespace std;

int self(int n)
{
    int self = n;

    while(n != 0)
    {
        self += n%10;
        n /= 10;
    }

    return self;
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int arr[10001] = {0, };

    for(int i=1; i<=10000; i++) 
    {
        int num = self(i);

        if(num <= 10000)
            arr[num]++; 
    }

    for(int i=1; i<=10000; i++) 
    {
        if(arr[i] == 0)
            cout<<i<<"\n";  
    }
}