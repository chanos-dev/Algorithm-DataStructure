#include <bits/stdc++.h>
using namespace std; 

pair<int, int> point[1'000'000];
int overlap[1'000'000];

int BS(int s, int e, int target)
{
    if (s > e) return 0;

    int mid = (s + e) / 2;

    if (overlap[mid] < target)
        return BS(mid + 1, e, target);
    else if (overlap[mid] > target)
        return BS(s, mid - 1, target);
    else
        return mid;
} 

bool compareOrder(pair<int, int> l, pair<int, int> r)
{
    return l.second < r.second;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        int v;  cin >> v;
        point[i] = { v, i };
    }

    sort(point, point + n);

    int curVal = -1000000005;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (curVal != point[i].first)
        {
            overlap[idx++] = point[i].first;
            curVal = point[i].first;
        }
    }

    sort(point, point + n, compareOrder);

    for (int i = 0; i < n; i++)
        cout << BS(0, idx, point[i].first) << " ";
}