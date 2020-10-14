#include <iostream>
using namespace std;

int number = 8;
int sorted[8];  

void Merge(int a[], int m, int middle, int n)
{
    int i = m;
    int j = middle + 1;
    int k = m;
    
    while(i <= middle && j <= n)
    {
        if(a[i] <= a[j])
        {
            sorted[k] = a[i];
            i++;
        } else
        {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    
    //남은 데이터 삽입
    if (i > middle)
    {
        for(int t = j; t <= n; t++)
        {
            sorted[k] = a[t];
            k++;
        }
    } else
    {
        for(int t = i; t <= middle; t++)
        {
            sorted[k] = a[t];
            k++;
        }
    }
    
    //정렬된 배열 삽입
    for(int t = m; t <= n; t++)
        a[t] = sorted[t];
}

void MergeSort(int a[], int m, int n)
{
    //크기가 1보다 큰경우
    if(m < n) {
        int middle = (m+n)/2;
        
        MergeSort(a, m, middle);
        MergeSort(a, middle+1, n);
        Merge(a, m, middle, n);
    }
}

int main() {
    int array[] = {7, 6, 5, 8, 3, 5, 9, 1};
    MergeSort(array, 0, number-1);
    for(int i = 0; i < number; i++)
        printf("%d ", array[i]);
    return 0;
}