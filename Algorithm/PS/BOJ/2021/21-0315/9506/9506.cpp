#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  


    int n;
    int sum;
    list<int> list;

    while(true)
    {
        cin>>n;
        
        if (n == -1)
            break;
        
        sum = 1;

        list.clear();
        list.push_back(1);

        for(int idx = 2; idx <= n/2; idx++)
        {
            if (n % idx == 0)
            {
                list.push_back(idx);
                sum += idx;
            }
        }

        if (n == sum)
        {
            cout<<n<<" = ";
            while(!list.empty())
            {
                if (list.size() != 1)
                    cout<<list.front()<<" + ";
                else
                    cout<<list.front();                
                list.pop_front();
            }
            cout<<"\n";
        }
        else
        {
            cout<<n<<" is NOT perfect.\n";
        }
    }
}