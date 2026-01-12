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
    private :
    struct node *head;

    public:

    SinglyCircular();                          // Constructor

    void InsertFirst(int no);                  // Insert node at the beginning 
    void InsertLast(int no);                   // Insert node at the Last
    void InsertAtPos(int no, int Pos);         // Insert node at Position

    void DeleteFirst();                        // Delete first node
    void DeletLast();                          // Delete last node 
    void DeleteAtPos(int Pos);                 // Delete node at a given position

    void Display();                            // Display all nodes
    int Count();                               // Count the number of nodes
};

SinglyCircular :: SinglyCircular()
{
    head = nullptr;
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

}

void SinglyCircular :: InsertLast(int no)
{

}

void SinglyCircular :: DeleteFirst()
{

}

void SinglyCircular :: DeletLast()
{

}

void SinglyCircular :: DeleteAtPos(int Pos)
{

}

int main()
{
    SinglyCircular obj;

    return 0;
}