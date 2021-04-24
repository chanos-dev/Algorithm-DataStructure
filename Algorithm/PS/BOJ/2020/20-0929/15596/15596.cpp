#include <bits/stdc++.h> 
using namespace std;

long long sum(std::vector<int> &a) {
	long long ans = 0;
    for(auto i : a )
        ans += i; 
	return ans;
}

int main()
{
    vector<int> vec;

    for(int i=0; i<10; i++)
        vec.push_back(i+1); 

    cout<<sum(vec);
}
