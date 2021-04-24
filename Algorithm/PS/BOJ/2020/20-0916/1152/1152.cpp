#include <bits/stdc++.h>

using namespace std; 

string Trim(string str)
{  
    string strTrim = str;

    if(strTrim[0] == ' ')
        strTrim = strTrim.substr(1, strTrim.length()-1); 

    if(strTrim[strTrim.length()-1] == ' ') 
        strTrim = strTrim.substr(0, strTrim.length()-1);    

    return strTrim;
}

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

    string str;

    getline(cin,str);   

    vector<string> vec = split(Trim(str), ' ');  

    cout<<vec.size()<<"\n"; 
}