#include<bits/stdc++.h>
using namespace std;

class BinaryTree
{ 
public:
    int val;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int n)
    {
        val = n;
        left = nullptr;
        right = nullptr;
    }

    ~BinaryTree()
    {

    } 
};

void preorder(BinaryTree* node)
{
    if (node == nullptr)
        return;
    
    cout<<node->val<<" ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(BinaryTree* node)
{
    if (node == nullptr)
        return;
    
    inorder(node->left);
    cout<<node->val<<" ";
    inorder(node->right);
}

void postorder(BinaryTree* node)
{
    if (node == nullptr)
        return;
    
    postorder(node->left);
    postorder(node->right);
    cout<<node->val<<" ";
}

void levelorder(BinaryTree* node)
{
    queue<BinaryTree*> q;

    q.push(node);

    while(!q.empty())
    {
        BinaryTree* n = q.front();
        cout<<n->val<<" ";
        q.pop();

        if (n->left != nullptr)
            q.push(n->left);
        if (n->right != nullptr)
            q.push(n->right);
    }
}

void levelorderLF(BinaryTree* node)
{
    queue<BinaryTree*> q;

    q.push(node);
    
    while(!q.empty())
    {
        int len = q.size();

        for(int i=0; i<len; i++)
        {
            BinaryTree* n = q.front();
            cout<<n->val<<" ";
            q.pop();

            if (n->left != nullptr)
                q.push(n->left);
            if (n->right != nullptr)
                q.push(n->right);
        }
        cout<<"\n";
    }    
}

int main()
{
    BinaryTree* t1 = new BinaryTree(1);
    BinaryTree* t2 = new BinaryTree(2);
    BinaryTree* t3 = new BinaryTree(3);
    BinaryTree* t4 = new BinaryTree(4);
    BinaryTree* t5 = new BinaryTree(5);
    BinaryTree* t6 = new BinaryTree(6);
    BinaryTree* t7 = new BinaryTree(7);
    
    t1->left = t2;
    t1->right = t3;

    t2->left = t4;
    t2->right = t5;

    t3->left = t6;
    t3->right = t7;

    // 1 2 4 5 3 6 7
    preorder(t1);
    cout<<"\n";
    // 4 2 5 1 6 3 7
    inorder(t1);
    cout<<"\n";
    // 4 5 2 6 7 3 1
    postorder(t1);
    cout<<"\n";
    // 1 2 3 4 5 6 7
    levelorder(t1);
    cout<<"\n";
    // 1
    // 2 3
    // 4 5 6 7
    levelorderLF(t1);
    cout<<"\nDone.";
}