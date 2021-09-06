#include<bits/stdc++.h>
using namespace std;

void StackPrint(stack<int> *stk);

int main()
{
    stack<int> stk;    

    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);    

    StackPrint(&stk);

    stk.push(1);
    stk.push(2); stk.pop();
    stk.push(3);
    stk.push(4); stk.pop();
    stk.push(5);

    StackPrint(&stk);    
}

void StackPrint(stack<int> *stk)
{
    cout<<"stack size : "<<stk->size()<<"\n";

    while(!stk->empty())
    {
        cout<<stk->top()<<"\n"; stk->pop();
    }
}