#include<iostream>
using namespace std;

// node structure for Singly Circular Linked List
struct node 
{
    int data;
    struct node *next;
};

// Class for Singly Circular Linked List
class SinglyCircular
{
private:
    node *head;
    node *tail;

public:
    SinglyCircular();                          // Constructor

    void InsertFirst(int no);                  // Insert node at the beginning 
    void InsertLast(int no);                   // Insert node at the Last
    void InsertAtPos(int no, int Pos);         // Insert node at Position

    void DeleteFirst();                        // Delete first node
    void DeleteLast();                         // Delete last node 
    void DeleteAtPos(int Pos);                 // Delete node at a given position

    void Display();                            // Display all nodes
    int Count();                               // Count the number of nodes
};

SinglyCircular :: SinglyCircular()
{
    head = nullptr;
    tail = nullptr;
}

void SinglyCircular :: Display()
{
}

int SinglyCircular :: Count()
{
    return 0;
}

void SinglyCircular :: InsertFirst(int no)
{
    node *newNode = new node;
    newNode->data = no;

    if(head == nullptr)
    {
        head = tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

void SinglyCircular :: InsertLast(int no)
{
}

void SinglyCircular :: InsertAtPos(int no, int Pos)
{
}

void SinglyCircular :: DeleteFirst()
{
}

void SinglyCircular :: DeleteLast()
{
}

void SinglyCircular :: DeleteAtPos(int Pos)
{
}

int main()
{
    SinglyCircular obj;

    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertFirst(51);

    return 0;
}
