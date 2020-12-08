#include <bits/stdc++.h> 
using namespace std; 

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[9] = {0,}; 

    int sum = 0; 
    bool isSelected = false;

    for(int i=0; i<9; i++)
    {
        cin>>arr[i];  
        sum += arr[i];
    }
    
    for (int i=0; i<8; i++)
    {
        for (int j=i+1; j<9; j++)
        {
            if (sum - (arr[i] + arr[j]) == 100)
            {
                arr[i] = 0;
                arr[j] = 0;
                isSelected = true;
                break;
            }
        }

        if (isSelected)
            break;
    }
    
    sort(arr, arr+9);

    for (int i=0; i<9; i++)
    {
        if(arr[i] != 0)
            cout<<arr[i]<<"\n";
    }
}