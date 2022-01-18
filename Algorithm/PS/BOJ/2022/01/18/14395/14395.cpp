#include<bits/stdc++.h>
using namespace std;

string ans;
set<long long> already;
string oper[] = {"*", "+", "/"};

bool check(long long a, long long b)
{
    queue<pair<long long, string>> q; 
    q.push({a, ""}); 

    while(!q.empty())
    {
        pair<long long, string> p = q.front(); q.pop(); 

        if (p.first == b)
        {
            ans = p.second;
            return true;
        }

        for(string o : oper)
        {
            long long v;
            if (o == "*") v = p.first * p.first;
            else if (o == "+") v = p.first + p.first;
            else v = 1;

            if (v <= 0 || v > b) continue;
            if (already.find(v) != already.end()) continue;  

            already.insert(v);
            q.push({v, p.second+o});
        } 
    }

    return false;
}

int main()
{  
    long long a, b; cin>>a>>b;
    if (a == b) 
    {
        cout<<"0";
        return 0;
    }
    else 
    {
        if (check(a, b)) cout<<ans;
        else cout<<"-1";
    } 
}