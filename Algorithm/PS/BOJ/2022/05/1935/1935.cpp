#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; cin>>n;
    string s; cin>>s;

    stack<double> stk; 
    double val[26] = {0};

    for(int i=0; i<n; i++)
        cin>>val[i];

    for(char c : s)
    {
        if (c == '*')
        {
            double o = stk.top();
            stk.pop();
            double t = stk.top();
            stk.pop();

            stk.push(t*o);
        }
        else if (c == '/')
        {
            double o = stk.top();
            stk.pop();
            double t = stk.top();
            stk.pop();

            stk.push(t/o);
        }
        else if (c == '+')
        {
            double o = stk.top();
            stk.pop();
            double t = stk.top();
            stk.pop();

            stk.push(t+o);
        }
        else if (c == '-')
        {
            double o = stk.top();
            stk.pop();
            double t = stk.top();
            stk.pop();

            stk.push(t-o);
        }
        else stk.push(val[c-'A']);
    }

    printf("%.2f",stk.top());
}