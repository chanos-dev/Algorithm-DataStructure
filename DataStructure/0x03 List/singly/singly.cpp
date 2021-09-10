#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int Data;
    struct Node *Next;
};

class LinkedList
{
    private:
        Node *Head;
        Node *Tail; 
        int count;
    public: 

        LinkedList()
        {
            Head = nullptr;
            Tail = nullptr;
            count = 0; 
        }
        ~LinkedList() { }

        void Add(int data)
        {
            Node* newNode = new Node;

            newNode->Data = data;
            newNode->Next = nullptr;
            count++;

            if (Head == nullptr)
            {
                Head = newNode;
                Tail = newNode;
            }
            else
            { 
                Tail->Next = newNode; 
                Tail = newNode; 
            }
            
            cout<<"Add Node {"<<newNode->Data<<"}.\n";
        }

        void Remove(int data)
        {
            if (Head == nullptr)    
            {
                cout<<"List is empty.\n";
                return;
            }
            
            if (Head->Data == data)
            {
                cout<<"Node->{"<<Head->Data<<"} is removed.\n";
                Node* tmp = Head;
                Head = Head->Next;
                free(tmp);
                count--;
            }
            else
            {
                Node* ptr = Head;
                Node* prev = ptr;

                while (ptr != nullptr)
                {
                    if (ptr->Data == data)
                    {
                        cout<<"Node->{"<<ptr->Data<<"} is removed.\n";
                        prev->Next = ptr->Next;

                        if (ptr == Tail)
                            Tail = prev;

                        free(ptr);
                        count--;
                        break;
                    }

                    prev = ptr;
                    ptr = ptr->Next;                    
                }

                if (ptr == nullptr)
                {
                    cout<<"Data{"<<data<<"} is not found.\n";
                    return;
                }
            }            
        }

        void Display()
        { 
             Node* ptr = Head;

             while (ptr != nullptr)
             {
                cout<<ptr->Data<<"-";
                ptr = ptr->Next;
             }
             cout<<"\n";
        }

        int Find(int data)
        {
            Node* ptr = Head;
            int index = 0;
            while (ptr != nullptr)
            {
                if (ptr->Data == data)
                {                    
                    return index;
                }
                else
                {
                    index++;
                    ptr = ptr->Next;
                }
            }

            return -1;
        }

        int Count()
        {
            return count;
        }

        void Clear()
        { 
            while (Head != nullptr)
            {
                Node* tmp = Head;
                Head = Head->Next;
                cout<<"Node->{"<<tmp->Data<<"} is removed.\n";
                free(tmp);
                count--;
            }
        }
};

int main()
{
    LinkedList mylist;
    mylist.Add(10);
    mylist.Add(20);
    mylist.Add(30);    
    mylist.Remove(30);
    mylist.Remove(20); 
    mylist.Remove(5);
    mylist.Add(40);
    mylist.Add(20);    
    mylist.Add(10);    
    cout<<"find index is "<<mylist.Find(30)<<"\n";
    mylist.Display(); 
    cout<<"list count is "<<mylist.Count()<<"\n";
    //mylist.Clear();
    mylist.Remove(10);
    mylist.Remove(40);
    mylist.Remove(20);
    mylist.Remove(10);
    mylist.Display();
    cout<<"list count is "<<mylist.Count()<<"\n";
    mylist.Add(40);
    mylist.Add(40);    
    mylist.Display();
}