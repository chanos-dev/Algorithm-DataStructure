#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    string s; cin>>s;

    int A[26] = {0,};

    for(char c : s)
    {
        A[c-'A']++;
    }

    char name[50] = {0, };
    int head = 0; 

    for(int i=0; i<26; i++)
    {
        if (A[i] < 1) continue;

        int cnt = A[i]/2;
        for(int j=0; j<cnt; j++)
        {
            name[head++] = i+'A';
            A[i]--; 
        } 
    }
    
    int tail = s.size()-1;
    for(int i=0; i<head; i++)
    {
        int left = A[name[i]-'A']; 
        if (left < 1) continue;

        A[name[i]-'A']--;
        name[tail--] = name[i];
    }

    bool isaddtion = false;
    for(int i=0; i<26; i++)
    {
        if (A[i] < 1) continue;

        if (isaddtion)
        {
            cout<<"I'm Sorry Hansoo";
            return 0;
        }

        name[head] = i+'A';
        isaddtion = true;
    }

    for(int i=0; i<s.size(); i++)
    {
        cout<<name[i];
    }
}