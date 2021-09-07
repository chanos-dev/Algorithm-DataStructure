#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int Data;
    struct Node *Prev;
};

class LinkedStack
{
    private:
        Node *top;
        int size;
    public:
        LinkedStack()
        {
            top = nullptr;
            size = 0;
        }

        ~LinkedStack()
        {

        }

        bool Empty()
        {
            return size == 0 ? true : false;
        }

        int Size()
        {
            return size;
        }

        int Top()
        {
            if (Empty())
            {
                cout<<"stack is empty()\n";
                return -1;
            }

            return top->Data;
        }

        void Push(int data)
        {
            Node* newNode = new Node();

            newNode->Data = data;
            newNode->Prev = nullptr;
            size++;

            if (top == nullptr)
            {
                top = newNode;                
            }            
            else
            {
                Node* tmp = top;
                top = newNode;
                top->Prev = tmp;
            } 
        }

        int Pop()
        {
            if (Empty())
            {
                cout<<"stack is empty()\n";
                return -1;
            }

            int data = top->Data;

            Node* tmp = top;
            top = top->Prev;
            free(tmp);
            size--;            

            return data;
        } 
};

int main()
{  
    LinkedStack stk;
    cout<<"stack empty is "<<(stk.Empty() ? "True" : "False")<<"\n";

    stk.Pop();
    stk.Top();

    stk.Push(1);
    stk.Push(2);
    stk.Push(3);
    stk.Push(4);

    cout<<"stack top is "<<stk.Top()<<"\n";
    cout<<"stack size is "<<stk.Size()<<"\n";
    cout<<"stack empty is "<<(stk.Empty() ? "True" : "False")<<"\n";

    while(!stk.Empty())
    {
        cout<<"pop : "<<stk.Pop()<<"\n";
    }

    stk.Pop(); 
    cout<<"stack empty is "<<(stk.Empty() ? "True" : "False")<<"\n";
}