#include <iostream>

using namespace std;

int array_count = 11;
int arr[11] = {10, 1, 11, 8, 2, 4, 3, 9, 7, 6, 5};


int Partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int pindex = l;
    int temp;
    
    for(int i = l; i < r; i++)
    {
        if(arr[i] <= pivot)
        {
            temp = arr[i];
            arr[i] = arr[pindex];
            arr[pindex] = temp;
            pindex++;
        }
    }
    
    temp = arr[r];
    arr[r] = arr[pindex];
    arr[pindex] = temp;
    
    return pindex;
}

void QuickSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int p = Partition(arr, l, r);
        
        QuickSort(arr, l, p-1);
        QuickSort(arr, p+1, r);
    }
}


int main(void)
{
    int arrCnt = sizeof(arr)/sizeof(int);
    
    QuickSort(arr, 0, arrCnt-1);
    
    for(int i = 0; i < arrCnt; i++)
        printf("%d ", arr[i]);
    
}