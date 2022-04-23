#include <bits/stdc++.h>
using namespace std;

int n; 
int A[101];
bool used[101];
string operation = "";
int maxV = -2111111111;
int minV = 2111111111;

void put(int k, int sum)
{    
    if (k == n)
    {
        if (sum > maxV)
            maxV = sum;
        
        if (sum < minV)
            minV = sum;

        return;
    }

    for(int i=0; i<operation.length(); i++)
    {
        if (used[i]) continue;

        used[i] = true;
        switch (operation[i])
        {
            case '+': put(k+1, sum + A[k]); break; 
            case '-': put(k+1, sum - A[k]); break; 
            case '*': put(k+1, sum * A[k]); break; 
            case '/': put(k+1, sum / A[k]); break; 
        } 
        used[i] = false;
    }
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    cin>>n;
    for(int i=0; i<n; i++)   
        cin>>A[i];
    
    for(int i=0; i<4; i++)
    {
        int v; cin>>v;

        if (i == 0) for(int j=0; j<v; j++) operation += "+";
        else if (i == 1) for(int j=0; j<v; j++) operation += "-";
        else if (i == 2) for(int j=0; j<v; j++) operation += "*";
        else if (i == 3) for(int j=0; j<v; j++) operation += "/";
    } 

    put(1, A[0]);

    cout<<maxV<<"\n"<<minV;
}