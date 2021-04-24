#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    int N;
    cin>>N;

    int cycle = N;
    int count = 0; 

    do
    {  
        if(cycle<10)
        {
            cycle = cycle*10 + cycle; 
        }
        else
        {
            int temp = 0;

            temp = (cycle/10) + (cycle%10);
            cycle = (cycle%10)*10 + temp%10;
        }  
        count++; 
    }while(cycle != N);

    cout<<count;
}