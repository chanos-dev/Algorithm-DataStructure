#include <bits/stdc++.h>
using namespace std;

void ReverseArray(int begin, int end, int* arr)
{ 
    int temp;

    while(true)
    {
        temp = arr[begin];
        arr[begin] = arr[end];
        arr[end] = temp;

        begin++;
        end--;

        if(begin >= end)break;
    }    
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[21] = {0,};

    for(int i=1; i<21; i++)
        arr[i] = i;

    int begin, end;

    for(int i=0; i<10; i++) 
    {
        cin>>begin>>end;

        ReverseArray(begin, end, arr);
    }
    
    for(int i=1; i<21; i++)
        cout<<arr[i]<<" ";
} 