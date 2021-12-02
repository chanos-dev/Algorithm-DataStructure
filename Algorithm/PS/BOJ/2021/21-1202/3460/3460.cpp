#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int t;
    cin>>t;

    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;

        vector<int> vec;
        int b = 1;

        while (n != 0)
        {
            vec.push_back(n % 2);
            n /= 2; 
        }

        for(int j=0; j<vec.size(); j++)
        {
            if (vec[j] == 1)
                cout<<j<<" ";
        }

        cout<<"\n";
    }
}