#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  
    
    string board[8];
    int white = 0;

    for(int i = 0; i < 8; i++)
    { 
        getline(cin, board[i]);

        for(int j = 0; j < 8; j ++)
        {
            if (i%2 == 0 && j%2 == 0)
            { 
                if (board[i][j] == 'F')
                    white++; 
            }
            else if (i%2 == 1 && j %2 == 1)
            { 
                if (board[i][j] == 'F')
                    white++; 
            }            
        }
    }

    cout<<white;
}