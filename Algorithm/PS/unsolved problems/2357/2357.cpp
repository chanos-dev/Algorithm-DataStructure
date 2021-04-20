//시간초과
#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int numbers[100001] = {0, };

    int N, M;

    cin>>N>>M;

    for(int i=0; i<N; i++)
    {
        int input;
        cin>>input;
        numbers[i] = input;
    }

    for(int i=0; i<M; i++)
    {
        int a,b;
        cin>>a>>b;

        list<int> sortNumbers;

        for(int j=a; j<=b; j++) 
            sortNumbers.push_back(numbers[j-1]); 

        sortNumbers.sort();

        cout<<sortNumbers.front()<<" "<<sortNumbers.back()<<"\n";
    }
}