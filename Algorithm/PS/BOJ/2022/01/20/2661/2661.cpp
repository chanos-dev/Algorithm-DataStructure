#include<bits/stdc++.h>
using namespace std;

string ans;
int n;
string su[] = {"1", "2", "3"};
bool isfind;

void ls(int k, string d)
{
    if (isfind) return;

    if (k == n)
    {
        ans = d;
        isfind = true;
        return;
    }     

    for(string s : su)
    {
        if (d[k-1] == s[0]) continue;
        
        string t = d+s[0];            
        bool bad = true;
        int st = 1;
        int rs = t.size()-1;
        for(int i=0; i<t.size()/2; i++)
        {
            for(int j=0; j<st; j++)
            {
                if (t[rs-j] != t[rs-st-j])
                {
                    bad = false;
                    break;
                }

                bad = true;
            }

            if (bad) break;
            st++;
        }

        if (bad) continue;
        
        ls(k+1, d+s);
    }
}

int main()
{
    cin>>n;

    ls(1, "1");
    cout<<ans;
}