#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int arr[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int k;
    cin >> k;

    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
 
        for (int i = x1; i <= x2; i++)
            for (int j = y1; j <= y2; j++)
                sum += arr[i - 1][j - 1];

        cout << sum << "\n";
    }
}