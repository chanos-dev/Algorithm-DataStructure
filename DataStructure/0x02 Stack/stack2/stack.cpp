#include<bits/stdc++.h>

#define MAX_STACK_SIZE 5

using namespace std;

int _stack[MAX_STACK_SIZE];
int top = -1;

bool empty();
void push(int i);
int pop();
void StackPrint();

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    StackPrint();
    pop();

    push(5);
    push(6);
    push(7);
    
    StackPrint();
}

bool empty()
{
    return top < 0 ? true : false;
}

void push(int i)
{
    if (top >= MAX_STACK_SIZE-1)
    {
        cout<<"STAKC IS FULL ("<<i<<")\n";
        return;
    }

    _stack[++top] = i;
}

int pop()
{
    if (empty())
    {
        cout<<"STAIC IS EMPTY \n";
        return -1;
    }

    return _stack[top--];
}

void StackPrint()
{
    while (!empty())
    {
        cout<<"pop : "<<pop()<<"\n";
    } 
}