#include <bits/stdc++.h>
using namespace std;

int N, K;
int ans = 0;

vector<int> monster;
vector<int> person;

int loseL = 0;
int save[25];
bool used[25];
bool bexit = false;

void escape(int k, int life)
{   
    if (life < 0) return;
    
    if (life >= 0)
    {        
        int s =0;
        for(int i=0; i<k; i++)        
            s += save[i];

        ans = max(s, ans); 
    }

    for (int i=0; i<N; i++)
    {
        if (!used[i])
        {
            save[k] = person[i];

            used[i] = true;
            loseL += monster[i];
            
            if (k == 0)
                escape(k+1, life-monster[i]);
            else
                escape(k+1, life-loseL);
            
            loseL -= monster[i];
            used[i] = false;
        }
    }
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    cin>>N>>K;

    for(int i=0; i<N; i++)
    {
        int m; cin>>m; monster.push_back(m);
    }

    for(int i=0; i<N; i++)        
    {
        int p; cin>>p; person.push_back(p);
    }

    escape(0, K);


    cout<<ans;
}