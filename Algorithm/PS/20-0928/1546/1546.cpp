#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int N;
    cin>>N;
    double sum=0;
    int max = -1;
    int arr[1000] = {0,};

    for(int i=0; i<N; i++)
    {
        int grade;
        cin>>grade;
        arr[i] = grade;
        if(grade >= max)
            max = grade;
    }
    
    for(int i=0; i<N; i++)
    {        
        sum += ((double)arr[i]/max)*100; 
    }

    cout.precision(5);
    cout<<sum/N;
}