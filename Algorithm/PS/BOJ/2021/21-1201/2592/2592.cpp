#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sum = 0;
    int arr[101] = {0,};

    for(int i=0; i<10;i++)
    {
        int n;
        cin>>n;
        sum+=n;

        arr[n/10]++;
    }

    cout<<sum/10<<"\n";

    int m = 0, c = 0;

    for(int i=1; i<sizeof(arr)/sizeof(int); i++)
    {
        if (arr[i] >= m)
        {
            m = arr[i];
            c = i * 10;
        }
    }

    cout<<c;
}