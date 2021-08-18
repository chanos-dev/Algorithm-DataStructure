#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; cin>>n;
    string str; cin>>str;

    vector<double> az;
    stack<double> value;

    for(int i=0; i<n; i++)
    {
        int x; cin>>x;
        az.push_back(x);
    }

    for(int i=0; i<str.length(); i++)
    {
        if (str[i] == '*')        
        {
            double a = value.top();
            value.pop();
            double b = value.top();
            value.pop();
            value.push(b*a);
        }
        else if (str[i] == '+')
        {
            double a = value.top();
            value.pop();
            double b = value.top();
            value.pop();
            value.push(b+a);
        }
        else if (str[i] == '/')
        {
            double a = value.top();
            value.pop();
            double b = value.top();
            value.pop();
            value.push(b/a);
        }
        else if (str[i] == '-')
        {
            double a = value.top();
            value.pop();
            double b = value.top();
            value.pop();
            value.push(b-a);
        }
        else
        {
            value.push(az[str[i]-65]);
        }
    }

    printf("%.2f",value.top());
}