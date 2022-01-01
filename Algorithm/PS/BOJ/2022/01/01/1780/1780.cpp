#include<bits/stdc++.h>
using namespace std;

int board[2187][2187];

int m = 0;
int z = 0;
int o = 0;

void paper(int r, int c, int t)
{
    int s = board[r][c];
    bool isS = true;

    for (int i=r; i<r+t; i++) 
    {
        for (int j=c; j<c+t; j++)
        {
            if(board[i][j] != s)
            {
                isS = false;
                break;
            }
        }
        if (!isS) break;
    }

    if (isS)
    {
        if (s == -1) m++;
        if (s == 0) z++;
        if (s == 1) o++;
    }
    //recursion
    else
    {
        // 9 -> 3
        int half = t / 3;

        paper(r, c, half);
        paper(r, c+half, half);
        paper(r, c+half*2, half); 

        paper(r+half, c, half);
        paper(r+half, c+half, half);
        paper(r+half, c+half*2, half);

        paper(r+half*2, c, half);
        paper(r+half*2, c+half, half);
        paper(r+half*2, c+half*2, half);
    }
}

int main()
{
    int N; cin>>N;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>board[i][j];
        }
    }

    paper(0, 0, N);

    cout<<m<<"\n";
    cout<<z<<"\n";
    cout<<o<<"\n";
}