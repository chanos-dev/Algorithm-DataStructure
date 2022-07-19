#include <bits/stdc++.h>
using namespace std;

char board[201][201];
int timer[201][201];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
    int r, c, n;
    cin >> r >> c >> n;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'O')
                timer[i][j] = 2;
        }
    }

    for (int t = 1; t < n; t++)
    {
        if (t % 2 == 0)
        {
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (timer[i][j] == t)
                    {
                        timer[i][j] = 0;
                        board[i][j] = '.';

                        for (int d = 0; d < 4; d++)
                        {
                            int nx = dx[d] + i;
                            int ny = dy[d] + j;

                            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                            if (timer[nx][ny] == t) continue;

                            timer[nx][ny] = 0;
                            board[nx][ny] = '.';
                        }
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (timer[i][j] == 0)
                    {
                        timer[i][j] = t + 3;
                        board[i][j] = 'O';
                    }
                }
            }
        } 
    }

    for (int i = 0; i < r; i++, cout << "\n")
        for (int j = 0; j < c; j++)
            cout << board[i][j];
}