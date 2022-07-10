#include <bits/stdc++.h>
using namespace std;

int getNumber(string s)
{
	int sum = 0;

	for (int i = 0; i < s.size(); i++)
		sum += s[i] - '0';

	return sum;
}

string convertToString(int n)
{
	string s; 
	stack<char> stk;

	while (n != 0)
	{
		stk.push((n % 10) + '0');
		n /= 10;
	}

	while (!stk.empty())
	{
		s += stk.top();
		stk.pop();
	}

	return s;
}

void three(string s, int c)
{
	int n = getNumber(s);
	string cs = convertToString(n);

	if (s != cs)
		c++;

	if (n < 10)
	{
		cout << c << "\n";
		cout << (n % 3 == 0 ? "YES" : "NO");
		return;
	}

	three(cs, c);
}

int main()
{
	string s;
	cin >> s;
	three(s, 0);
}