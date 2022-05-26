#include <bits/stdc++.h>
using namespace std; 

int K;
int lotto[15];
int pick[6];
bool used[50];

void print(int k)
{
	if (k == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << pick[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < K; i++)
	{
		if (used[lotto[i]]) continue;

		if (k > 0) 
			if (pick[k - 1] > lotto[i]) continue; 

		pick[k] = lotto[i];
		used[lotto[i]] = true;
		print(k + 1);
		used[lotto[i]] = false;
	} 
}

int main()
{
	while (true)
	{
		cin >> K;
		if (K == 0) break;
		
		for (int i = 0; i < K; i++)
			cin >> lotto[i];

		print(0);
		cout << "\n";
	}
}