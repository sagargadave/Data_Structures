#include <iostream>
using namespace std;

// node structure for Doubly Linked List
struct node 
{
    int data;
    struct node * prev;
    struct node * next;
};

// Class for Doubly Linked List
class DoublyLL 
{

    private:
    struct node *head;

    public:
        DoublyLL();                          // Constructor
        void InsertFirst(int no);            // Insert node at the beginning 
        void InsertLast(int no);             // Insert node at the Last
        void InsertAtPos(int pos, int no);   // Insert node at Position

        void Display();                      // Display all nodes
        int Count();                         // Count the number of nodes

        void DeleteFirst();                  // Delete first node
        void DeleteLast();                   // Delete last node 
        void DeleteAtPos(int pos);           // Delete node at a given position
};

DoublyLL::DoublyLL() 
{
    head = nullptr;    
}

int DoublyLL::Count()
{
    return 0;
}

void DoublyLL:: Display()
{

}

void DoublyLL::InsertFirst(int no) 
{
    struct node *newNode = new node;

    newNode->data = no;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if(head == nullptr)
    {
        head = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void DoublyLL::InsertLast(int no) 
{
    struct node * newNode = new node;

    newNode->data = no;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if(head == nullptr)
    {
        head = newNode;
    }
    else
    {
        struct node *temp = head;

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        newNode->prev = temp;
        temp->next = newNode;
    }
}

void DoublyLL::InsertAtPos(int pos,int no) 
{

}

void DoublyLL::DeleteFirst()
{

}

void DoublyLL::DeleteLast()
{
    
}

void DoublyLL::DeleteAtPos(int pos)
{
    
}

// Main function
int main() 
{
    DoublyLL dll;

    return 0;
}