#include <bits/stdc++.h>
using namespace std;

void Josephus(int n, int k)
{
    if(n <= 1)
    {
        cout<<"<1>";
        return;
    }
    else
    {
        int arr[n+1] = {0,};
        int removeArr[n+1] = {0,};
        int removeCnt = 0;
        int index = 1; 

        while(removeCnt < n)
        {
            int move = 0; 

            while(move <= k)
            {
                if(index > n)
                    index = 1;

                if(removeArr[index] == 0)
                {
                    move++;
                    if(move == k)
                        break;
                }

                index++; 
            } 

            if(removeArr[index] == 0)
            {
                removeArr[index]++;                
                removeCnt++;
                arr[removeCnt] = index;
            }   
        }

        cout<<"<";
        for(int i=1; i<=n; i++)
        {
            if(i != n)
                cout<<arr[i]<<", ";
            else
                cout<<arr[i];
        }
        cout<<">";
    }    
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;

    cin>>n>>k;

    Josephus(n, k); 
}

