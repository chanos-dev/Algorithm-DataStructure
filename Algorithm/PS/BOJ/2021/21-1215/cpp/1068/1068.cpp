#include<iostream>
#include<vector>

using namespace std;

vector<int> tree[50]; 
bool vist[50];
int l = 0;
int root = 0;

void check(int i, int r)
{
    // 삭제 노르면 탈출
    if (i == r)
        return;

    // leaf면 ++
    if (tree[i].size() <= 1 && i != root)
    {
        l++;
        return;
    }

    if (tree[i].empty())
    {
        l++;
        return;
    }
    
    for(int n : tree[i])
    {
        if (vist[n]) continue;

        vist[n] = true;

        check(n, r);
    }
}

int main()
{
    int n; cin>>n;

    for(int i=0; i<n; i++)
    {
        int node; cin>>node;

        if (node == -1)
        {
            root = i;
            continue;
        }

        tree[node].push_back(i);
        tree[i].push_back(node);
    } 
    
    int r; cin>>r;

    for(int i=0; i<tree[r].size(); i++)
    {
        int p = tree[r][i];

        int f = 0;
        for(int j=0; j<tree[p].size(); j++)
        {
            if (tree[p][j] == r)
            {
                f = j;
                break;
            }
        }

        tree[p].erase(tree[p].begin()+f);
    } 

    check(root,r);
    cout<<l;
}