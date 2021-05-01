#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n;
    string s;

    cin>>n;

    cin.ignore(256,'\n');

    for(int i=0; i<n; i++)
    {
        getline(cin, s);
        
        vector<string> v;
        string buffer;
        stringstream stream(s);

        while(getline(stream, buffer, ' '))
        {
            v.push_back(buffer);
        }
        
        float f = stof(v[0]);

        for(int j=1; j<v.size(); j++)
        {            
            if(v[j] == "@")
                f *= 3;
            else if(v[j] == "%")
                f += 5;
            else if(v[j] == "#")
                f -= 7;
        } 
        
        printf("%.2f\n",f);
    }
}