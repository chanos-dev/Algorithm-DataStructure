#include <iostream>
#include <vector>
using namespace std;

vector<int> friends[2'005];
bool vist[2'005];
bool ans;

void find(int n, int k)
{
    if (ans) return;

    if (k >= 5)
    {
        ans = true;
        return;
    }    

    for (int c : friends[n])
    {
        if (vist[c]) continue;

        vist[c] = true;
        find(c, k + 1);
        vist[c] = false;
    } 
}

int main()
{
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for (int i = 0; i < n - 1; i++)
    {
        vist[i] = true;
        find(i, 1);

        if (ans)
        {
            cout << "1";
            return 0;
        }        
        vist[i] = false;
    }

    cout << "0";
}