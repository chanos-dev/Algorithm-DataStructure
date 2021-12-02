#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int k; cin>>k;

    for(int i=0; i<k; i++)
    {
        int n; cin>>n;
        vector<int> vec;

        for(int j=0; j<n; j++)
        {
            int v; cin>>v; 
            vec.push_back(v);
        }

        sort(vec.begin(), vec.end(), compare);

        int lg = 0;

        for (int i = 0; i < n - 1; i++)
            if (lg < vec[i] - vec[i+1])
                lg = vec[i] - vec[i+1];

        cout<<"Class "<<i+1<<"\n";
        cout<<"Max "<<vec[0]<<", Min "<<vec[n-1]<<", Largest gap "<<lg<<"\n";
    }
}