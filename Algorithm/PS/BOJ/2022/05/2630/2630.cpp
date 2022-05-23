#include <bits/stdc++.h>
using namespace std;
int N;
int board[130][130];
int w, b;

void ColoredPater(int s, int e, int n)
{
	if (s < 0 || e > N) return;
	int c = 0;
	for (int i = s; i < s + n; i++)
		for (int j = e; j < e + n; j++)
			c += board[i][j];

	if (c == 0) w++;
	else if (c == n * n) b++;
	else 
	{
		int half = n / 2;
		// 1 
		ColoredPater(s, e, half);
		// 2
		ColoredPater(s, e + half, half);
		// 3
		ColoredPater(s + half, e, half);
		// 4
		ColoredPater(s + half, e + half, half);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	ColoredPater(0, 0, N);

	cout << w << "\n";
	cout << b;
}