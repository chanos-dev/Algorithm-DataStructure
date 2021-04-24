#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;

    cin>>n;

    int m = n-1;

    bool isEven = n%2; 

    for(int i=0; i<n; i++, cout<<"\n")
    {
        for(int j=0; j<n*2-1; j++)
        {
            if ( (j >= m - i) && (j <= m + i)) 
            {                
                if ((j-1)%2 == isEven) cout<<"*";
                else if ((i == n-1) && (j == 0)) cout<<"*";
                else cout<<" ";
            }
            else 
            {   
                if (m+i < j) break;             
                cout<<" ";                
            }
        }        

        isEven = !isEven;
    }
}