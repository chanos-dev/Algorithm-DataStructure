#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int N;
    cin>>N; 
    list<int> list; 

    for(int i=0; i<N; i++)
    {
        int num;
        cin>>num;
        list.push_back(num);
    } 
    list.sort();

    
    cout<<list.front()<<" "<<list.back();
}