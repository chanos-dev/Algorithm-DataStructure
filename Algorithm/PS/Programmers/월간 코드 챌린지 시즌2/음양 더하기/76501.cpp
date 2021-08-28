#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// absolutes_len은 배열 absolutes의 길이입니다.
// signs_len은 배열 signs의 길이입니다.
int solution(int absolutes[], size_t absolutes_len, bool signs[], size_t signs_len) 
{
    int sum = 0;

    for(int i=0; i<absolutes_len; i++)
    {
        if (signs[i])
        {
            sum += absolutes[i];
        }
        else
        {
            sum += -absolutes[i];
        }
    }

    return sum;
}

int main()
{
    int foo[3] = {4, 7, 12};
    bool boo[3] = {true, false, true};

    printf("%d", solution(foo, 3, boo, 3));
}