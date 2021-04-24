#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int N;
    cin>>N;
    
    for(int i=0; i<N; i++)
    {
        string str;
        cin>>str;
        
        int score = 0;
        int ox = 0;

        for(int i=0; i<str.length(); i++)
        {
            if(str[i] == 'O')
            {
                score = score + 1;
                ox += score;
            }
            else 
                score = 0;       
        }
        cout<<ox<<"\n";
    }
}