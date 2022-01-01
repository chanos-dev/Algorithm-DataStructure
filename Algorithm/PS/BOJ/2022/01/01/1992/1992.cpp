#include<bits/stdc++.h>
using namespace std;

int board[64][64];
char cboard[64][64];

vector<char> ans;

void tree(int r, int c, int t)
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
        if (!isS) break;;
    }

    // recursion
    if (isS)
    {
        ans.push_back(s+'0');
    }
    else
    {
        int half = t / 2;

        ans.push_back('(');
        tree(r, c, half);
        tree(r, c + half, half);
        tree(r + half, c, half);
        tree(r + half, c + half, half);
        ans.push_back(')');
    } 
}

int main()
{
    int N; cin>>N;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            cin>>cboard[i][j];
            board[i][j] = cboard[i][j] - '0';
        }
    
    tree(0, 0, N);

    for(char c : ans)
    {
        cout<<c;
    }
}