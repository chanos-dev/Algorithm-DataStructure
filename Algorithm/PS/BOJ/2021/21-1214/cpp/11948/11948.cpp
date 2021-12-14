#include<bits/stdc++.h>
using namespace std;

int main()
{ 
    int g1[4];
    int g2[2];

    for(int i=0; i<4; i++)
        cin>>g1[i];

    for(int i=0; i<2; i++)
        cin>>g2[i];

    sort(g1, g1+4);
    sort(g2, g2+2);

    cout<<g1[1]+g1[2]+g1[3]+g2[1];
} 