#include <bits/stdc++.h>
using namespace std; 

int board[65][65];
int N;
vector<char> ans;

void tree(int s, int e, int size)
{
    int c = 0;
    for(int i=s; i<s+size; i++)
        for(int j=e; j<e+size; j++)
            if (board[i][j]) c++;
    
    if (c == 0)
        ans.push_back('0');
    else if (c == size * size)
        ans.push_back('1');
    else
    {
        int h = size/2;
        ans.push_back('(');
        tree(s, e, h);
        tree(s, e+h, h);
        tree(s+h, e, h);
        tree(s+h, e+h, h);
        ans.push_back(')');
    }
}

int main()
{    
    cin>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            char v; cin>>v;
            board[i][j] = v - '0';
        }
    
    tree(0, 0, N);
    for(char c : ans)
        cout<<c;
}