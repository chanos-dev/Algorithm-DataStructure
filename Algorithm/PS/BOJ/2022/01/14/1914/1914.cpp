#include<bits/stdc++.h>
using namespace std;

void hanoi(int n, int a, int b, int c)
{
    if (n == 1)
    {
        cout<<a<<" "<<c<<"\n";
        return;
    }

    hanoi(n-1, a, c, b);
    cout<<a<<" "<<c<<"\n";
    hanoi(n-1, b, a, c);
}

char ans[32];
bool add[32]; 

int main()
{ 
    int n; cin>>n;

    fill_n(ans, 32, '0'); 
    fill_n(add, 32, false); 
    ans[0] = '2';    

    int idx = 0;
    int eidx = 0;

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<=idx; j++)
        {
            int v = (ans[j]-'0') * 2;   
            if (v >= 10)
            {
                ans[j] = (v % 10) + '0';
                add[j+1] = true;

                if (j >= eidx)
                    eidx++;
            }
            else
            {
                ans[j] = v + '0';
            }
        }

        for(int j=0; j<=eidx; j++)
        {
            if (add[j])
            {
                ans[j] += 1;
                add[j] = false;
            }
        }

        idx = eidx; 
    } 

    if (n == 1)
        cout<<"1\n";
    else
    {
        for(int i=idx; i>=0; i--)
        {
            if (i==0) cout<<(char)(ans[i]-1);
            else cout<<ans[i];
        }
        cout<<"\n";
    }

    if (n < 21)
        hanoi(n, 1, 2, 3);
}