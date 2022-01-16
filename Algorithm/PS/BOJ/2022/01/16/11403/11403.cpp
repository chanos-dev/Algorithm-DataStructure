#include<bits/stdc++.h>
using namespace std;

int board[101][101];
bool vist[101][101];

vector<int> pos[101];

void check(int i, int r)
{    
    for(int c : pos[i])
    {
        if(vist[i][c]) continue;
        vist[i][c] = true;

        board[r][c] = 1;
        check(c, r);
    }
}

int main()
{
    int n; cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>board[i][j];

            if (board[i][j] == 1)
                pos[i].push_back(j);
        }
    }

    for(int i=0; i<n; i++)
    {
        check(i, i); 

        for(int j=0; j<n; j++)
            fill_n(vist[j], n, false);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}