#include <iostream>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a;
    cin>>a;
    switch (a)
    {
        case 90 ... 100:
            cout<<"A";
            break;
        case 80 ... 89:
            cout<<"B";
            break;
        case 70 ... 79:
            cout<<"C";
            break;
        case 60 ... 69:
            cout<<"D";
            break;
        default:
            cout<<"F";
            break;
    }
}