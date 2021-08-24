#include <bits/stdc++.h>
using namespace std;

bool CheckHigherNumber(queue<string> q)
{
    char first = q.front()[0]; q.pop();

    while(!q.empty())
    {
        
        if (first < q.front()[0])
        {
            return true;
        }

        q.pop();
    }

    return false;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;

    for(int i=0; i<n; i++)
    {
        queue<string> printer; 

        int m; cin>>m;
        int find; cin>>find; 

        for(int j=0; j<m; j++)
        {
            string p; cin>>p;

            if (j == find) 
                printer.push(p.append("_YES"));     
            else
                printer.push(p.append("_NO"));                 
        }  

        int count = 0;

        while(!printer.empty())
        {
            // 1. 더 높은 중요도가 이쓰면
            if (CheckHigherNumber(printer))
            {
                // 뒤로 보내기이~
                printer.push(printer.front());
                printer.pop();
            }
            else    
            {
                // 바로 print~ 
                count++; 
                if (printer.front().find("YES") != string::npos)
                {
                    cout<<count<<"\n";
                }
                printer.pop();
            } 
        }
    }
}

