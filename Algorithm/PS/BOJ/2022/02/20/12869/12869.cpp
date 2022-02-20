#include<bits/stdc++.h>
using namespace std;

int ans[61][61][61];
int scv[3];
int t;

struct attack
{
    int one;
    int two;
    int three;
    attack() {}
    attack(int one, int two, int three) : one(one), two(two), three(three) {}
};

attack attacks[6] = {
    attack(9, 3, 1),
    attack(9, 1, 3),
    attack(3, 9, 1),
    attack(3, 1, 9),
    attack(1, 3 ,9),
    attack(1, 9, 3),
};

void bfs()
{
    queue<attack> q;
    q.push(attack(scv[0], scv[1], scv[2]));
    ans[scv[0]][scv[1]][scv[2]] = 1;

    while(!q.empty())
    {
        attack a = q.front(); q.pop(); 
                
        for(int d=0; d<6; d++)
        {
            attack g = attacks[d];

            int none = max(0, a.one - g.one);
            int ntwo = max(0, a.two - g.two);
            int nthree = max(0, a.three - g.three);

            if (ans[none][ntwo][nthree] != 0) continue;
            ans[none][ntwo][nthree] = ans[a.one][a.two][a.three]+1;
            q.push(attack(none, ntwo, nthree));
        }
    }

}

int main()
{
    cin>>t;
    for(int i=0; i<t; i++)
        cin>>scv[i];
    
    bfs();
    cout<<ans[0][0][0]-1;
}