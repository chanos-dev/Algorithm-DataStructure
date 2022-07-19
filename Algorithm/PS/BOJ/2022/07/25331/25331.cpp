#include <bits/stdc++.h>
using namespace std;

int board[7][7];
int playboard[7][7];

int ans = 987654321;
int dropball;

queue<pair<int, int>> rq;

void drop()
{
    for (int j = 0; j < 7; j++)
    {
        for (int i = 6; i >= 0; i--)
        {
            if (playboard[i][j] != 0)
            {
                for (int k = i + 1; k < 7; k++)
                {
                    if (playboard[k][j] != 0)
                        break;

                    playboard[k][j] = playboard[k - 1][j];
                    playboard[k - 1][j] = 0;
                }
            }
        }
    }
}

void checkRow()
{
    for(int i=6; i>=0; i--)
    {
        int con = 0;

        for(int j=0; j<7; j++)
        {
            if (playboard[i][j] != 0) con++;
            else if (con > 0)
            {
                for(int z=j-1; z >= (j-con); z--)
                {
                    if (playboard[i][z] == con)
                        rq.push({i,z});
                }
                con = 0;
            }
        }

        if (con > 0)
        {
            for(int z=6; z >= (7-con); z--)
            {
                if (playboard[i][z] == con)
                    rq.push({i,z});
            }
        }
    }
}

void checkCol()
{    
    for(int i=0; i<7; i++)
    {
        int con = 0;
        
        for(int j=6; j>=0; j--)
        {
            if (playboard[j][i] == 0)
                continue;

            con++;            
        }

        if (con == 0)       
            continue;
            
        for(int j=6; j>=0; j--)
        {
            if (playboard[j][i] == con)
                rq.push({j, i});
        }
    }
}

bool remove()
{
    if (rq.empty())
        return false;

    while (!rq.empty())
    {
        pair<int, int> p = rq.front();
        rq.pop();

        playboard[p.first][p.second] = 0;
    }

    return true;
}

void play(int c)
{
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            playboard[i][j] = board[i][j];

    playboard[0][c] = dropball;
    drop();
    while (true)
    {
        checkRow();
        checkCol();
        if (!remove())
            break;
        drop();
    }

    int cnt = 0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            if (playboard[i][j] != 0)
                cnt++;

    ans = min(ans, cnt);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            cin >> board[i][j];

    cin >> dropball;

    for (int c = 0; c < 7; c++)
        play(c);

    cout << ans;
}