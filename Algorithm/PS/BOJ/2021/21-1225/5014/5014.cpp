#include<bits/stdc++.h>
using namespace std;


queue<pair<int,int>> q;
bool vist[1000001];

int F, S, G, U, D;
bool isarrive;
int totalcnt;

// void Elevator(int s, int cnt)
// {     
//     if (F < s || s <= 0) return;
//     if (vist[s]) return;
//     vist[s] = true; 

//     if (s == G)
//     {
//         isarrive = true;
//         totalcnt = cnt;
//         return;
//     }

//     if (U != 0)
//         Elevator(s+U, cnt+1);
//     if (D != 0)
//         Elevator(s-D, cnt+1);
// }

int main()
{
    cin>>F>>S>>G>>U>>D;

    queue<pair<int,int>> q;
    //Elevator(S, 0);

    q.push({S, 0});

    while(!q.empty())
    {
        pair<int, int> p = q.front(); q.pop();

        if (F < p.first || p.first <= 0) continue;
        if (vist[p.first]) continue;
        vist[p.first] = true; 

        if (p.first == G)
        {
            isarrive = true;
            totalcnt = p.second;            
        }

        q.push({p.first+U, p.second+1});
        q.push({p.first-D, p.second+1});
    }

    if (isarrive) cout<<totalcnt;
    else cout<<"use the stairs";
}