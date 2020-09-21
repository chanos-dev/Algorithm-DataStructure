#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int Classes[2][6] = {0, };

    int total, max;

    cin>>total>>max;

    for(int i=0; i<total; i++)
    {
        int sex, Class;

        cin>>sex>>Class;  

        Classes[sex][Class-1]++;
    }  

    int rooms = 0;

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<6; j++)
        {
            rooms += Classes[i][j] / max;

            if(Classes[i][j] % max)            
                rooms++; 
        }
    }

    cout<<rooms;
}