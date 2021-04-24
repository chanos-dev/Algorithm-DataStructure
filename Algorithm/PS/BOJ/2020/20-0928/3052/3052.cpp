#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int count = 0;
    int arr[42] = {0, };

    for(int i=0; i<10; i++)
    {
        int n;
        cin>>n;
        if(arr[n%42] == 0)
        {
            count++;
            arr[n%42]++;
        }        
    }

    cout<<count;
}