#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n[5];
    int min = 101, count;

    for(int i=0; i<5; i++)
    {
        cin>>n[i];

        if (n[i] < min)
            min = n[i];
    }

    while(true)
    {
        min++;
        count = 0;

        for(int i=0; i<5; i++)
        {
            
            if (min % n[i] == 0)
                count++;
        }

        if (count >= 3)
            break; 
    }

    cout<<min;
}