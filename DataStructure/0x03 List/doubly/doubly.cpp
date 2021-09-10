#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int Data;
    Node* Prev;
    Node* Next;
};

class DoublyList
{
    private:
        Node *Head;
        Node *Tail;
        int count; 
    public:
        DoublyList()
        {
            Head = nullptr;
            Tail = nullptr;
            count = 0;
        }
        ~DoublyList()
        {

        }

        bool empty()
        {
            return count == 0 ? true : false;
        }

        int size()
        {
            return count;
        }

        void Add(int data)
        {
            Node* newNode = new Node;
            newNode->Data = data;
            newNode->Next = nullptr;
            newNode->Prev = nullptr;

            count++; 

            if (Head == nullptr)
            {   
                Head = newNode;  
                Tail = newNode;
            }
            else
            { 
                Tail->Next = newNode;
                newNode->Prev = Tail;
                Tail = newNode;
            }            
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

                if (Head->Next != nullptr)
                { 
                    Head = Head->Next;
                    Head->Prev = nullptr;
                }
                else
                { 
                    Head = nullptr;
                    Tail = nullptr;
                } 

                free(tmp);
                count--; 
                return;
            };

            if (Tail->Data == data)
            {
                cout<<"Node->{"<<Tail->Data<<"} is removed.\n";
                Node* tmp = Tail;
                Tail = Tail->Prev; 
                Tail->Next = nullptr;
                free(tmp);
                count--;
                return;
            }

            Node* ptr = Head;
            Node* prev = ptr;
            
            while (ptr != nullptr)
            {
                if (ptr->Data == data)
                {
                    cout<<"Node->{"<<ptr->Data<<"} is removed.\n";

                    prev->Next = ptr->Next;
                    ptr->Next->Prev = prev; 

                    free(ptr);
                    count--;
                    break;
                }
                
                prev = ptr;
                ptr = ptr->Next;
            }
        }

        void DisplayForward()
        { 
            Node* ptr = Head;

            while (ptr != nullptr)
            {
               cout<<ptr->Data<<"-";
               ptr = ptr->Next;
            }
            cout<<"\n";
        }

        void DisplyBackward()
        {
            Node* ptr = Tail; 

            while (ptr != nullptr)
            {
               cout<<ptr->Data<<"-";
               ptr = ptr->Prev;
            }
            cout<<"\n";
        }
};

int main()
{
    DoublyList mylist;
    mylist.Add(10);
    mylist.Add(20);
    mylist.Add(30);     
    mylist.Add(40);    
    mylist.Add(50);    
    mylist.Add(10);     
    mylist.DisplayForward();  
    mylist.DisplyBackward();
    mylist.Remove(40);
    mylist.Remove(10); 
    mylist.Remove(10); 
    mylist.Remove(50); 
    mylist.DisplayForward();  
    mylist.DisplyBackward();
    mylist.Remove(20); 
    mylist.Remove(30); 
    mylist.DisplayForward();  
    mylist.DisplyBackward();
    mylist.Add(30);     
    mylist.Add(40);    
    mylist.Add(50);    
    mylist.Add(10);  
    mylist.Remove(10); 
    mylist.Add(20);
    mylist.DisplayForward();  
    mylist.DisplyBackward();
}