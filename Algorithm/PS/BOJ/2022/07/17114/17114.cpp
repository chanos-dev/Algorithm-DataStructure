#include <iostream>
#include<queue>
using namespace std;

int dust[51][51];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void moveCol(int c, int from, int to)
{ 
	if (from < to)
	{
		for (int i = from; i < to; i++)
		{
			dust[i][c] = dust[i + 1][c];
		} 
	}
	else
	{
		for (int i = from; i > to; i--)
		{
			dust[i][c] = dust[i - 1][c];
		}
	}
}

void moveRow(int r, int from, int to)
{
	if (from < to)
	{
		for (int i = from; i < to; i++)
		{
			dust[r][i] = dust[r][i + 1];
		}
	}
	else
	{ 
		for (int i = from; i > to; i--)
		{
			if (dust[r][i - 1] == -1)
				dust[r][i] = 0;
			else
				dust[r][i] = dust[r][i - 1];
		}
	}
}

int main()
{    
	int R, C, T; cin >> R >> C >> T; 
	for(int i=0; i<R; i++)
		for (int j = 0; j < C; j++)
			cin >> dust[i][j]; 

	int trobot, brobot;
	for (int i = 2; i < R; i++)
	{
		if (dust[i][0] == -1)
		{
			trobot = i;
			brobot = i + 1;
			break;
		}
	}

	queue<pair<pair<int, int>, int>> sq;
	for (int t = 1; t <= T; t++)
	{
		// spread
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
			{
				if (dust[i][j] < 1) continue;

				int sp = 0;
				int sd = dust[i][j] / 5;
				for (int d = 0; d < 4; d++)
				{
					int nx = dx[d] + i;
					int ny = dy[d] + j;

					if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
					if (dust[nx][ny] == -1) continue;

					sp++;
					sq.push({ {nx, ny},sd });
				}
				dust[i][j] -= sp * sd;
			} 

		while (!sq.empty())
		{
			pair<pair<int, int>, int> p = sq.front(); sq.pop();
			dust[p.first.first][p.first.second] += p.second;
		}

		// move
		moveCol(0, trobot - 1, 0);
		moveRow(0, 0, C);
		moveCol(C - 1, 0, trobot + 1);
		moveRow(trobot, C - 1, 0); 

		moveCol(0, brobot + 1, R);
		moveRow(R - 1, 0, C);
		moveCol(C - 1, R - 1, brobot);
		moveRow(brobot, C - 1, 0);
	}

	int ans = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			ans += dust[i][j];

	cout << ans + 2;
}  