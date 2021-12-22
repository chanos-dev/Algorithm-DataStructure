#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s, e; cin>>s>>e; 

    int cnt = 0;

    while(s != e)
    {
        if (e % 10 == 1)        
            e /= 10;
        else
        {
            if (e % 2 == 1)
            {
                cout<<"-1";
                break;   
            }

            e /= 2;
        }

        cnt++;

        if (s == e)
        {
            cout<<cnt+1;
            break;
        }
        else if (s > e)
        {
            cout<<"-1";
            break;
        }
    }
} 