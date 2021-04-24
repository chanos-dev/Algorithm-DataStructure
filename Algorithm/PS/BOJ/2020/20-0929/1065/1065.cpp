#include <bits/stdc++.h>
using namespace std;

bool onlynum(int n)
{  
    int num = (n/10%10) - n%10;  

    do
    {  
        if(num != (n/10%10) - n%10)
            return false;
        else 
        {
            n /= 10; 
            if(n<10) break;
        }

    } while (n != 0); 
    return true;   
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;
    int count = 0;
    cin>>n;

    for(int i=1; i<=n; i++)
    { 
        if(onlynum(i)) count++;  
    } 

    cout<<count;
}