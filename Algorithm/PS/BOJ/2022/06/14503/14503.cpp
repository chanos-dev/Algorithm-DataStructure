#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int ground[53][53];

int N, M;
int r, c, d;
int ans;

pair<int, int> directions[4] = {
    {0, -1},
    {-1, 0},
    {0, 1},
    {1, 0},
};

void robot()
{
   while (true)
   {
      if (ground[r][c] == 0)
      {
         ground[r][c] = 2;
         ans++;
      }

      int nx, ny;
      int rotateCnt = 0;
      pair<int, int> p;

      do
      {
         p = directions[d--];
         rotateCnt++;
         if (d < 0)
            d = 3;

         nx = r + p.x;
         ny = c + p.y;

         if (rotateCnt > 4)
            break;
      } while (ground[nx][ny]);

      if (rotateCnt > 4)
      {
         pair<int, int> b = directions[d];
         if (ground[r + b.x][c + b.y] == 1)
            return;

         nx = r + b.x;
         ny = c + b.y;
         d++;
         if (d > 3)
            d = 0;
      }

      r = nx;
      c = ny;
   }
}

int main()
{
   cin >> N >> M;
   cin >> r >> c >> d;
   for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
         cin >> ground[i][j];
   robot();
   cout << ans;
}