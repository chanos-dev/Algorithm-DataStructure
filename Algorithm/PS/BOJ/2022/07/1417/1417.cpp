#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{    
    int N; cin >> N;
    int da; cin >> da; 
    int ans = 0;
    priority_queue<int> pq;

    for (int i = 0; i < N-1; i++)
    {
        int v; cin >> v; 
        pq.push(v);
    }

    while (!pq.empty() && da <= pq.top())
    {
        da++;
        int o = pq.top(); pq.pop(); 
        o--;
        pq.push(o);
        ans++;
    }

    cout << ans;
} 