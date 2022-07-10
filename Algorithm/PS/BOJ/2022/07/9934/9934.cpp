#include <bits/stdc++.h>
using namespace std;

int tree[1025];
vector<int> ans[11];

void getTree(int s, int e, int d)
{      
    if (s == e)
    {
        ans[d].push_back(tree[s]);    
        return;
    }

    int m = (s + e) / 2;

    ans[d].push_back(tree[m]);
    getTree(s, m-1, d+1);
    getTree(m+1, e, d+1);
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int k; cin>>k;

    int c = pow(2, k)-1;
    
    for(int i=0; i<c; i++)
        cin>>tree[i];
    
    getTree(0, c-1, 0);

    for(int i=0; i<k; i++, cout<<"\n")
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
}