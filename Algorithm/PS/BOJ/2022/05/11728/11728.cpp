#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int A, B; cin>>A>>B;
    int Arr[A];
    int Brr[B];

    for(int i=0; i<A; i++)
        cin>>Arr[i];

    for(int i=0; i<B; i++)
        cin>>Brr[i];
    
    vector<int> ans;

    int apos = 0;
    int bpos = 0;
    while(ans.size() != A+B)
    {
        if (apos >= A || bpos >= B) break;
        
        if (Arr[apos] > Brr[bpos])
            ans.push_back(Brr[bpos++]);
        else
            ans.push_back(Arr[apos++]);
    } 

    for(int i=apos; i<A; i++)
        ans.push_back(Arr[i]);
    for(int i=bpos; i<B; i++)
        ans.push_back(Brr[i]);

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}