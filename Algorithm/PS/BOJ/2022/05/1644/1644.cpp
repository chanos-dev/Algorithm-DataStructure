#include <bits/stdc++.h>
using namespace std;

bool prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> primes;

    for (int i = 2; i <= n; i++)
        if (prime(i))
            primes.push_back(i);

    int ans = 0;
    int sum = 0;
    int e = 0;
    for (int s = 0; s < primes.size(); s++)
    {
        while(e < primes.size() && sum < n)
            sum += primes[e++];
        
        if (sum == n) ans++;
        sum -= primes[s];
    }

    cout<<ans;
}