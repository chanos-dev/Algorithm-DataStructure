#include<iostream>
using namespace std;

int main(void)
{
	int i, j;
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

	for(i = 0; i < 9; i++)
	{ 
        j = i;
        while(array[j] > array[j+1])
        {
            int temp = array[j+1];
            array[j+1] = array[j];
            array[j] = temp;
            j--;

            if(j<0) break;
        }
	}
	
	for(i = 0; i < 10; i++)
		cout<<array[i]<<" ";
	
	return 0;
}