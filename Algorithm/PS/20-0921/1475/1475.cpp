#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    int arr[10] = {0, };
    
    string str;
    cin>>str;

    for(int i=0; i<str.length(); i++)
        arr[str[i] - '0']++;

    int max = -1;
    int sn = 0;     

    for(int i=0; i<10;i++) 
    {
        if((i==6) || (i==9)) 
        {
            sn += arr[i];  
            continue;
        }

        if(arr[i] >= max) max = arr[i];
    }

    if(sn%2) sn++;

    sn /= 2; 

    if(sn != 0)
        max > sn ? cout<<max : cout<<sn;
    else
        cout<<max; 
}