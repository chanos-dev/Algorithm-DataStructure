#include <bits/stdc++.h>
using namespace std; 

vector<string> split(string str, char delimiter) {
    vector<string> vec;
    stringstream stream(str);
    string temp;
 
    while (getline(stream, temp, delimiter)) {
        vec.push_back(temp);
    }
 
    return vec;
} 

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int t;

    cin>>t;

    cin.ignore(256, '\n');

    while(t--)
    {
        string str;
        getline(cin,str); 

        vector<string> splitItems = split(str, ' ');

        for(auto s : splitItems)
        {
            for(int i = s.length()-1; i >= 0; i--)
            {
                cout<<s[i];
            }

            cout<<" ";
        }        

        cout<<"\n";
    }
}