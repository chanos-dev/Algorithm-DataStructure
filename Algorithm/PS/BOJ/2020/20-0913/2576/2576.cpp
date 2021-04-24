#include <bits/stdc++.h>  

using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    const int SIZE = 7;

    int arr[SIZE] = {0,}; 
    int min = 101;
    int sum = 0;

    for(int i=0; i<SIZE; i++)
    {
        cin>>arr[i];  
    } 

    for(int i=0; i<SIZE; i++)
    {
        if(arr[i] % 2)
        {       
            sum += arr[i]; 
            if(min >= arr[i])
            {
                min = arr[i];
            }
        }
    }

    if(sum == 0)
    {
        cout<<"-1";
    }
    else
    {
        cout<<sum<<"\n";
        cout<<min;
    }
    
}