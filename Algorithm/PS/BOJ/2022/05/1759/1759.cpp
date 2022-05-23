#include <bits/stdc++.h>
using namespace std;

int l, c;
vector<char> vec;
bool used[27];
char ans[16];

void password(int k, int m, int j)
{
	if (l == k)
	{
		if (m < 1 || j < 2) return;

		for (int i = 0; i < l; i++)
			cout << ans[i];
		cout << "\n";
		return;
	}

	for (char c : vec)
	{
		int idx = c - 'a';

		if (used[idx]) continue;
		if (k > 0 && ans[k - 1] > c) continue;

		used[idx] = true;
		ans[k] = c;

		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			password(k + 1, m + 1, j);
		else
			password(k + 1, m, j + 1);

		used[idx] = false;
	}
}

int main()
{
	cin >> l >> c;

	for (int i = 0; i < c; i++)
	{
		char c; cin >> c;
		vec.push_back(c);
	}

	sort(vec.begin(), vec.end());

	password(0, 0, 0);
}