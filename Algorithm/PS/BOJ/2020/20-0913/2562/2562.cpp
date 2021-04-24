#include <bits/stdc++.h>  

using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    const int SIZE = 9;

    int arr[SIZE] = {0,}; 
    int index = 0;
    int max = 0;

    for(int i=0; i<SIZE; i++)
    {
        cin>>arr[i]; 
        if(arr[i] > max)
        {
            max = arr[i];
            index = i+1;
        }
    } 

    cout<<max<<"\n";  
    cout<<index;
}