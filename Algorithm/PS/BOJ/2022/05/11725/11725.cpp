#include <iostream>
#include <vector>
using namespace std;

vector<int> node[100'005];
int ans[100'005];

void find(int n)
{
    for (int c : node[n])
    {
        if (ans[c] == 0)
        {
            ans[c] = n;
            find(c);
        }        
    }
}

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int a, b; cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    ans[1] = 1;
    find(1);

    for (int i = 2; i <= n; i++)
        cout << ans[i] << "\n";
}