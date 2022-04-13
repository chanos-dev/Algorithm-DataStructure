#include <bits/stdc++.h>
using namespace std;

int arr[301][301];
int ans[301][301];

void rotate(int x1, int y1, int x2, int y2, int r)
{
    // exit condition
    if (x1 > x2 || y1 > y2)
        return;

    int nr = r % ((x2-x1) * 2 + (y2-y1) * 2);
    for (int i = 0; i < nr; i++)
    {
        // down
        for (int i = x1; i <= x2; i++)
        {
            if (i + 1 <= x2)
                ans[i + 1][y1] = arr[i][y1];
            else
                ans[i][y1 + 1] = arr[i][y1];
        }

        // right
        for (int j = y1; j <= y2; j++)
        {
            if (j + 1 <= y2)
                ans[x2][j + 1] = arr[x2][j];
            else
                ans[x2 - 1][j] = arr[x2][j];
        }

        // up
        for (int i = x2; i >= x1; i--)
        {
            if (i - 1 >= x1)
                ans[i - 1][y2] = arr[i][y2];
            else
                ans[i][y2 - 1] = arr[i][y2];
        }
        // left
        for (int j = y2; j >= y1; j--)
        {
            if (j - 1 >= y1)
                ans[x1][j - 1] = arr[x1][j];
        }

        for (int i = x1; i <= x2; i++)
            arr[i][y1] = ans[i][y1];
        for (int j = y1; j <= y2; j++)
            arr[x2][j] = ans[x2][j];
        for (int i = x2; i >= x1; i--)
            arr[i][y2] = ans[i][y2];
        for (int j = y2; j >= y1; j--)
            arr[x1][j] = ans[x1][j];
    }

    rotate(x1 + 1, y1 + 1, x2 - 1, y2 - 1, r);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            ans[i][j] = arr[i][j];
        }

    rotate(0, 0, n - 1, m - 1, r);

    for (int i = 0; i < n; i++, cout << "\n")
        for (int j = 0; j < m; j++)
            cout << ans[i][j] << " ";
}