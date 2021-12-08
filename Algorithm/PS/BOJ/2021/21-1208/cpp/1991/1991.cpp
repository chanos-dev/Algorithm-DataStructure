#include <bits/stdc++.h>
using namespace std;

class Node
{ 
private:
    char v;
public:
    Node* l;
    Node* r;
    Node(char c);
    ~Node();
    char GetValue();
};

Node::Node(char c)
{
    this->v = c;
    l = nullptr;
    r = nullptr;
}

Node::~Node()
{
}

char Node::GetValue()
{
    return this->v;
}


Node* t[26];

Node* FindNode(char c)
{
    if (t[c - 65] != nullptr)
        return t[c - 65];

    Node* node = new Node(c);
    t[c-65] = node;
    return node;
}

void preorder(Node* node)
{
    if (node == nullptr)
        return;
    
    cout<<node->GetValue();
    preorder(node->l);
    preorder(node->r);
}

void inorder(Node* node)
{
    if (node == nullptr)
        return;
    
    inorder(node->l);
    cout<<node->GetValue();
    inorder(node->r);
}

void postorder(Node* node)
{
    if (node == nullptr)
        return;
    
    postorder(node->l);
    postorder(node->r);
    cout<<node->GetValue();
}

int main()
{ 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);  

    int n; cin>>n;
    cin.ignore(256, '\n');

    fill_n(t, 26, nullptr); 

    for(int i=0; i<n; i++)
    {
        string s; getline(cin, s);  

        Node* node = FindNode(s[0]);

        if (s[2] != '.') 
            node->l = FindNode(s[2]); 

        if (s[4] != '.')
            node->r = FindNode(s[4]); 
    }   

    preorder(t[0]);
    cout<<"\n";
    inorder(t[0]);
    cout<<"\n";
    postorder(t[0]);
} 