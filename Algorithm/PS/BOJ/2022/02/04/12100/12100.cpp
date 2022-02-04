#include<bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
int board[21][21];
int arrow[5]; 

void easy(int k)
{ 
    if (k == 5)
    {
        int temp[n][n];
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) 
                temp[i][j] = board[i][j];  

        for(int d=0; d<5; d++)
        {
            bool made[n][n];
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    made[i][j] = false;

            // left
            if (arrow[d] == 0)
            {
                for(int i=0; i<n; i++)
                {
                    for(int j=1; j<n; j++)
                    {
                        for(int z=j-1; z>=0; z--)
                        { 
                            if (temp[i][z] == 0)
                            {
                                temp[i][z] = temp[i][z+1];
                                temp[i][z+1] = 0;
                            }                             
                            else if (temp[i][z] == temp[i][z+1] && !made[i][z])
                            {
                                temp[i][z] *= 2;
                                made[i][z] = true;
                                temp[i][z+1] = 0;
                                break;
                            }
                            else break;
                        }
                    }
                }
            }
            // up
            else if (arrow[d] == 1)
            {
                for(int j=0; j<n; j++)
                {
                    for(int i=1; i<n; i++)
                    {
                        for(int z=i-1; z>=0; z--)
                        { 
                            if (temp[z][j] == 0)
                            {
                                temp[z][j] = temp[z+1][j];
                                temp[z+1][j] = 0;
                            } 
                            else if (temp[z][j] == temp[z+1][j] && !made[z][j])
                            {
                                temp[z][j] *= 2;
                                made[z][j] = true;
                                temp[z+1][j] = 0;
                                break;
                            }
                            else break;
                        }
                    }
                }
            }
            // right
            else if (arrow[d] == 2)
            {
                for(int i=0; i<n; i++)
                {
                    for(int j=n-2; j>=0; j--)
                    {
                        for(int z=j+1; z<n; z++)
                        {                          
                            if (temp[i][z] == 0)
                            {
                                temp[i][z] = temp[i][z-1];
                                temp[i][z-1] = 0;
                            } 
                            else if (temp[i][z] == temp[i][z-1] && !made[i][z])
                            {
                                temp[i][z] *= 2;
                                made[i][z] = true;
                                temp[i][z-1] = 0;
                                break;
                            }
                            else break;
                        }
                    }
                }
            }
            // down
            else
            {
                for(int j=0; j<n; j++)
                {
                    for(int i=n-2; i>=0; i--)
                    {
                        for(int z=i+1; z<n; z++)
                        { 
                            if (temp[z][j] == 0)
                            {
                                temp[z][j] = temp[z-1][j];
                                temp[z-1][j] = 0;
                            } 
                            else if (temp[z][j] == temp[z-1][j] && !made[z][j])
                            {
                                temp[z][j] *= 2;
                                made[z][j] = true;
                                temp[z-1][j] = 0;
                                break;
                            }
                            else break;
                        }
                    }
                }
            }
        }  

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                ans = max(ans, temp[i][j]); 

        return;
    } 

    for(int d=0; d<4; d++)
    {
        arrow[k] = d;
        easy(k+1);
    }
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>board[i][j];
    
    easy(0);  

    cout<<ans;       
}