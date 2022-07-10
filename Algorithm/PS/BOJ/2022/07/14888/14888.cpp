#include <bits/stdc++.h>
using namespace std;

int n;
int N[12];
string oper = "";

bool used[12];

int maxV = -2100000000;
int minV = 2100000000;

void input(int k, int sum)
{
    if (n == k)
    {
        if (maxV < sum)
            maxV = sum;
        
        if (minV > sum)
            minV = sum;

        return;
    }

    for(int i=0; i<oper.size(); i++)
    {
        if (used[i]) continue;
        used[i] = true;

        if (oper[i] == '+') input(k+1, sum + N[k]);
        else if (oper[i] == '-') input(k+1, sum - N[k]);
        else if (oper[i] == '*') input(k+1, sum * N[k]);
        else if (oper[i] == '/') input(k+1, sum / N[k]);

        used[i] = false;
    }
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>N[i];
    
    for(int i=0; i<4; i++)
    {
        int c; cin>>c;

        for(int j=0;j<c; j++)
        {
            if (i==0) oper += "+";
            else if (i==1) oper += "-";
            else if (i==2) oper += "*";
            else if (i==3) oper += "/";
        }
    }

    input(1, N[0]);

    cout<<maxV<<"\n";
    cout<<minV<<"\n";
}