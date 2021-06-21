#include<iostream>
using namespace std;

int main(void)
{
    int count[5];
    int array[30] = {
        1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
        3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
        3, 1, 4, 3, 5, 1, 2, 1, 1, 1
    };

    for (int i=0; i<5; i++)
    {
        count[i] = 0;
    }

    for (int i=0; i<30; i++)
    {
        count[array[i] - 1]++;
    }

    for (int i=0; i<5; i++)
    {
        for (int j=0; j<count[i]; j++)
        {
            cout<<i+1<<" ";        
        }
    }
}