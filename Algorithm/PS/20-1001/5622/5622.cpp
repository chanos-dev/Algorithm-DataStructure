#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);   

    string str;
    cin>>str;
    int time = 0;

    for(int i=0; i<str.length(); i++)
    { 
        int num = (str[i] - 'A'); 

        if((num == 18) || (num >= 21)) 
            num -= 1; 
            
        num = (num / 3) > 7 ? 10 : (num / 3) + 3;

        time += num;
    }

    cout<<time;
}