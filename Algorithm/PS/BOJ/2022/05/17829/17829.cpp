#include <bits/stdc++.h>
using namespace std;  

int board[1025][1025];
int N;

int ttt(int s, int e, int size)
{ 
    if (size < 2) 
        return board[s][e];
        
    int h = size/2;
    vector<int> v;
    v.push_back(ttt(s, e, h));        
    v.push_back(ttt(s, e+h, h));
    v.push_back(ttt(s+h, e, h));
    v.push_back(ttt(s+h, e+h, h)); 
    sort(v.begin(), v.end());    
    return v[v.size()-2]; 
}

int main()
{    
    cin>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>board[i][j];
    
    cout<<ttt(0, 0, N);
}