// N - 운동 횟수
// m - 초기 맥박
// M - 최대 맥박
// T - 맥박 증가량
// R - 휴식 시 맥박 감소량
#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int N, m, M, T, R;
    int hour = 0;
    int X = 0;

    cin>>N>>m>>M>>T>>R;    

    if (m + T > M)
    {
        cout<<"-1";
        return 0;
    }

    X = m;

    while(N > 0)
    {  
        if (X + T <= M) 
        {
            X += T; 
            N--;
        }
        else
        {
            X -= R;
            if (X < m) 
                X = m;
        }

        hour++;
    }

    cout<<hour;
}