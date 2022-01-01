#include<bits/stdc++.h>
using namespace std;

int board[128][128];

int w, b;

void paper(int r, int c, int t)
{
    int s = board[r][c];
    bool isS = true;

    for(int i=r; i<r+t; i++)
    {
        for(int j=c; j<c+t; j++)
        {
            if (board[i][j] != s)
            {
                isS = false;
                break;
            }
        }
        if (!isS) break;
    }

    if (isS)
    {
        if (s == 0) w++;
        else b++;
    }
    //recursion
    else
    {
        int half = t / 2;

        paper(r, c, half);
        paper(r + half, c, half);
        paper(r, c + half, half);
        paper(r + half, c + half, half);
    }
}

int main()
{
    int N; cin>>N;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            cin>>board[i][j];
        }
        
    paper(0, 0, N);

    cout<<w<<"\n";
    cout<<b<<"\n";
}