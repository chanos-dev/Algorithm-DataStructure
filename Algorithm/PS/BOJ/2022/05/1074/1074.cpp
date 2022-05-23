#include <bits/stdc++.h>
using namespace std;

int N, r, c;
int ans;
 
void Z(int n, int x, int y)
{
	if (x == r && y == c)
	{
		cout << ans;
		return;
	}

	if (n == 0) return;

	// 반
	int s = 1 << (n - 1);
	int sx = s + x;
	int sy = s + y;
	// 왼위
	if (r < sx && c < sy)
		Z(n - 1, x, y);
	// 오위
	else if (r < sx && c >= sy)
	{
		ans += s * s;
		Z(n - 1, x, y + s);
	}
	// 왼아래
	else if (r >= sx && c < sy)
	{
		ans += s * s * 2;
		Z(n - 1, x + s, y);
	}
	// 오아래
	else if (r >= sx && c >= sy)
	{
		ans += s * s * 3;
		Z(n - 1, x + s, y + s);
	}
}

int main()
{
	cin >> N >> r >> c;
	Z(N, 0, 0);
}