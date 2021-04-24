#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int N;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        int scores;
        cin>>scores;
        int arr[1000] = {0,};
        int avg = 0;
        for(int j=0; j<scores; j++)
        {
            int score;
            cin>>score;
            arr[j] = score;
            avg += score;
        }

        avg /= scores;
        int count = 0;
        for(int j=0; j<scores; j++)
        {
            if(arr[j] > avg)
                count++;
        }  
        
        cout<<fixed;
        cout.precision(3);
        cout<<(double)count/scores*100<<"%\n";
    }
}