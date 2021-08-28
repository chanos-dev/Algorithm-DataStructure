#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool check(string s)
{ 
    stack<char> stk; 

    if (s[0] == ')' ||
        s[0] == '}' ||
        s[0] == ']')
        return false;

    for(int i=0; i<s.length(); i++)
    {
        if (s[i] == '(' ||
            s[i] == '{' ||
            s[i] == '[')
            stk.push(s[i]);
        else
        {
            if (abs(s[i] - stk.top()) > 2)
                return false;            
            
            stk.pop();
        } 
    }

    return true;
}

string replace(string s, int idx)
{
    string ns = s;
    for (int i=0; i<idx; i++)
    { 
        char temp = ns[0];

        for (int j=0;j<ns.length();j++)        
        { 
            ns[j] = ns[j+1];
        }
        ns[ns.length()-1] = temp;
    }

    return ns;
}

int solution(string s) 
{
    int answer = 0;        

    for(int i=0; i<s.length(); i++)
    {
        cout<<replace(s, i)<<"\n";
        //answer += check(ns) ? 1 : 0;
    }

    return answer;
}

int main()
{
    solution("[](){}");
}