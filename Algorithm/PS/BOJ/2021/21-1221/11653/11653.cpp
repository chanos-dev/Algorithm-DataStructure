#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;

    vector<int> vec;
    int s = 2;

    while (n > 1)
    {
        if (n % s == 0)
        {
            n /= s;
            vec.push_back(s);
        }
        else
        {
            s++;
        }
    }

    for (int v : vec)
    {
        cout << v << "\n";
    }
}