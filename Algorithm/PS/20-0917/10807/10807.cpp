#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[201] = {0, };
    
    int N, v;

    cin>>N;

    for(int i=0; i<N; i++)
    {
        int input;        
        cin>>input;
        arr[input+100]++;
    }

    cin>>v;
    cout<<arr[v+100];
}