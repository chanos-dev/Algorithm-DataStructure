#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[5] = {0,};
    int max = 0;

    for(int i=0; i<5; i++)
    {
        cin>>arr[i];
        max += arr[i];
    }

    max /= 5;

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<4-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout<<max<<"\n";
    cout<<arr[2];
}