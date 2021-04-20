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

    for(int i=0; i<t; i++)
    {
        string str;
        getline(cin,str); 

        vector<string> splitItems = split(str, ' ');

        cout<<"Case #"<<i+1<<": ";

        for(int j=splitItems.size()-1; j>=0; j--)
        {
            cout<<splitItems[j]<<" ";
        } 

        cout<<"\n";
    }
}