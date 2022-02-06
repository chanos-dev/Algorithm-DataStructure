#include<bits/stdc++.h>
using namespace std;

#define len 9
int board[len][len];
bool rowBoard[len][len+1];
bool colBoard[len][len+1];
bool rectBoard[len][len+1];
int idx = 0;

int room(int x, int y)
{
    return x/3*3 + y/3;
}

void sudoku(int k)
{ 
    int x = k % len;
    int y = k / len;
    
    if (k > len*len)
    {
        for(int i=0; i<len; i++)
        {        
            for(int j=0; j<len; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
        exit(0);
    }

    if (board[x][y] != 0)
    {
        sudoku(k+1);
    }
    else
    {
        for(int n=1; n<10; n++)
        {
            if (!rowBoard[x][n] && !colBoard[y][n] && !rectBoard[room(x,y)][n])
            {
                rowBoard[x][n] = true;
                colBoard[y][n] = true;
                rectBoard[room(x,y)][n] = true;
                board[x][y] = n;
                sudoku(k+1);
                board[x][y] = 0;
                rectBoard[room(x,y)][n] = false;
                colBoard[y][n] = false;
                rowBoard[x][n] = false;
            }
        }
    }
}

int main()
{  
    for(int i=0; i<len; i++)
        for(int j=0; j<len; j++)
        {
            cin>>board[i][j];
            if (board[i][j] != 0)            
            {
                rowBoard[i][board[i][j]] = true;
                colBoard[j][board[i][j]] = true;
                rectBoard[room(i,j)][board[i][j]] = true; 
            }
        }

    sudoku(0);
}