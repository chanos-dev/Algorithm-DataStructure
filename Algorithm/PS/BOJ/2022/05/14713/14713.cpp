#include <bits/stdc++.h>
using namespace std;

queue<string> angs[101];
queue<string> QL;

queue<string> SplitString(string s, char sepa)
{
	queue<string> q;
	stringstream stream(s);
	string split;
	while (getline(stream, split, ' '))
		if (split != "")
			q.push(split);
	return q;
}

int main()
{
	int angsCnt = 0;
	int n; cin >> n;
	cin.ignore(256, '\n');
	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);

		angs[i] = SplitString(s, ' ');
		angsCnt += angs[i].size();
	}
	string L;
	getline(cin, L);
	QL = SplitString(L, ' ');
	int LCnt = QL.size();

	while (!QL.empty())
	{
		bool isFind = false;
		for (int i = 0; i < n; i++)
		{
			if (angs[i].empty()) continue;

			if (QL.front() == angs[i].front())
			{
				isFind = true;
				QL.pop();
				angs[i].pop();
				angsCnt--;
				LCnt--;
			}
		}

		if (!isFind) break;
	}

	if (angsCnt+LCnt > 0) cout << "Impossible";
	else cout << "Possible";
}