#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int A, B, C;
    int arr[10] = {0,};
    cin>>A>>B>>C;

    long long D = A*B*C;

    while(D != 0)
    {
        arr[D%10]++;
        D /= 10;
    }

    for(int i=0; i<10; i++)
        cout<<arr[i]<<"\n";
}