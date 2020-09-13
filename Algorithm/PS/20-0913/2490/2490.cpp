#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[3][5] = {0,};

    for(int i=0; i<3; i++)
    {
        int zero = 0;

        cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
        for(int j=0; j<4; j++)
        {            
            if(!arr[i][j]) 
                zero++;
        }
        arr[i][4] = zero;
    } 
    
    for(int i=0; i<3; i++)
    {
        switch (arr[i][4])
        {
            case 4:
                cout<<"D\n";
                break;
            case 3:
                cout<<"C\n";
                break;
            case 2:
                cout<<"B\n";
                break;
            case 1:
                cout<<"A\n";
                break;
            default:
                cout<<"E\n";
                break;
        }
    }
}