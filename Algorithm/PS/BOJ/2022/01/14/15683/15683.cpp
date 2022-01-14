#include<bits/stdc++.h>
using namespace std;

int r, c; 
int office[8][8];
int input[8][8];

void left(int x, int y, int v)
{
    for(int i=y-1; i>=0; i--)
    {
        if (office[x][i] == 6) break;
        if (office[x][i] != 0 && office[x][i] != 9) continue;
        office[x][i] = v;
    }
}

void right(int x, int y, int v)
{
    for(int i=y+1; i<c; i++)
    {
        if (office[x][i] == 6) break;
        if (office[x][i] != 0 && office[x][i] != 9) continue;
        office[x][i] = v;
    }
}

void up(int x, int y, int v)
{
    for(int i=x-1; i>=0; i--)
    {
        if (office[i][y] == 6) break;
        if (office[i][y] != 0 && office[i][y] != 9) continue;
        office[i][y] = v;
    }
}

void down(int x, int y, int v)
{
    for(int i=x+1; i<r; i++)
    {
        if (office[i][y] == 6) break;
        if (office[i][y] != 0 && office[i][y] != 9) continue;
        office[i][y] = v;
    }
}

void horizontal(int x, int y, int v)
{
    left(x, y, v);
    right(x, y, v);
}

void vertical(int x, int y, int v)
{
    up(x,  y, v);
    down(x, y, v);
}  

struct cctv
{
    int x;
    int y;
    int number;
    int arrow;
    bool vist[4];
    
    cctv() {}
    cctv(int X, int Y, int N, int A) : x(X), y(Y), number(N), arrow(A) 
    {
        fill_n(vist, 4, false);
    }

    void check()
    { 
        if (number == 1 && arrow == 0) right(x, y, 9);
        if (number == 1 && arrow == 1) down(x, y, 9);
        if (number == 1 && arrow == 2) left(x, y, 9);
        if (number == 1 && arrow == 3) up(x, y, 9);
        //
        if (number == 2 && arrow == 0) horizontal(x, y, 9);
        if (number == 2 && arrow == 1) vertical(x, y, 9);
        if (number == 2 && arrow == 3) horizontal(x, y, 9);
        if (number == 2 && arrow == 4) vertical(x, y, 9);
        //
        if (number == 3 && arrow == 0) up(x, y, 9);
        if (number == 3 && arrow == 0) right(x, y, 9); 

        if (number == 3 && arrow == 1) right(x, y, 9);
        if (number == 3 && arrow == 1) down(x, y, 9); 

        if (number == 3 && arrow == 2) down(x, y, 9);
        if (number == 3 && arrow == 2) left(x, y, 9); 

        if (number == 3 && arrow == 3) left(x, y, 9);
        if (number == 3 && arrow == 3) up(x, y, 9); 
        //
        if (number == 4 && arrow == 0) horizontal(x, y, 9);
        if (number == 4 && arrow == 0) up(x, y, 9); 

        if (number == 4 && arrow == 1) vertical(x, y, 9);
        if (number == 4 && arrow == 1) right(x, y, 9); 

        if (number == 4 && arrow == 2) horizontal(x, y, 9);
        if (number == 4 && arrow == 2) down(x, y, 9); 

        if (number == 4 && arrow == 3) vertical(x, y, 9);
        if (number == 4 && arrow == 3) left(x, y, 9);  
        //
        if (number == 5)
        {
            horizontal(x, y, 9);
            vertical(x, y, 9);
        }
    } 
};

vector<cctv*> cctvCollection; 
int cctvsCount = 0;

cctv* cctvs[8];
bool vist[8][8];

int ans = 99999;

void check()
{
    int l = 0;

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
        {
            if (office[i][j] == 0)
                l += 1;
        }

    if (ans > l)
        ans = l;
} 

void land(int k)
{
    if (k == cctvsCount)
    {  
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                office[i][j] = input[i][j];

        for(int i=0; i<k; i++)
        {
            cctvs[i]->check();
        }

        check();     
        return;
    }


    for(int c=k; c<cctvsCount; c++)
    {
        cctv* cctv = cctvCollection[c];

        for(int a=0; a<4; a++)
        {
            if (vist[cctv->x][cctv->y] || cctv->vist[a]) continue;
            
            vist[cctv->x][cctv->y] = true;

            cctvs[k] = cctv;
            cctvs[k]->vist[a] = true;
            cctvs[k]->arrow = a;

            land(k+1);

            if (k!=0) cctvs[k]->vist[a] = false;

            vist[cctv->x][cctv->y] = false;
        }
    } 
}

int main()
{
    cin>>r>>c; 

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
        {
            cin>>input[i][j];
            if (input[i][j] > 0 && input[i][j] < 6)
            {
                cctvCollection.push_back(new cctv(i, j, input[i][j], 0));
            }
        }

    cctvsCount = cctvCollection.size();  

    land(0);
    cout<<ans;
}