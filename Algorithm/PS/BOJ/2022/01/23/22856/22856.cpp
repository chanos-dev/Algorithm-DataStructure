#include<bits/stdc++.h>
using namespace std;

struct node
{
    int left;
    int right;
    node() {}
    node(int l, int r): left(l), right(r) {}
};

map<int, node> m;
int lastv, ans;

void inorder(int v)
{
    if (m[v].left != -1)
        inorder(m[v].left);
    lastv = v;
    if (m[v].right != -1)
        inorder(m[v].right);
}

void move(int v)
{
    if (m[v].left != -1)
    {
        move(m[v].left);
        ans++;
    }
    
    if (lastv == v)
    {
        cout<<ans;
        exit(0);
    }
    ans++;

    if (m[v].right != -1)
    {
        move(m[v].right);
        ans++;
    }
}

int main()
{
    int t; cin>>t;

    for(int i=0; i<t; i++)
    {
        int p, l, r; cin>>p>>l>>r;
    
        m.insert({p, node(l, r)});
    }

    inorder(1);
    move(1);
}