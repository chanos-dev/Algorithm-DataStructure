#include<iostream>
#include<vector>

using namespace std;

int cnt = 0;
vector<int> computer[101];
bool vist[101];

void check(int i)
{
    for (int com : computer[i])
    {
        if (vist[com])
            continue;

        vist[com] = true;
        cnt++;

        check(com);
    }
}

int main()
{
    int com; cin >> com;
    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;

        computer[a].push_back(b);
        computer[b].push_back(a);
    }

    check(1);
    cout << cnt;
}