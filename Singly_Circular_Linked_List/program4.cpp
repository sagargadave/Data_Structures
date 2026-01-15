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
    struct node *tail;

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
    tail = nullptr;
}

void SinglyCircular :: Display()
{
    struct node *temp = head;

    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    while(temp != head);

    cout<<"\n";
    
}

int SinglyCircular :: Count()
{
    return 0;
}

void SinglyCircular :: InsertFirst(int no)
{
    struct node *newNode = new node;

    newNode->data = no;
    newNode->next = nullptr;

    if(head == nullptr)
    {
        head = newNode;
        newNode->next = newNode;
        tail = head;

    }
    else
    {
        tail->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void SinglyCircular :: InsertLast(int no)
{
    struct node *newNode = new node;

    newNode->data = no;
    newNode->next = head;

    tail->next = newNode;
    tail = newNode;
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

    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertFirst(51);

    obj.Display();
    
    obj.InsertLast(101);
    obj.InsertLast(121);
    obj.InsertLast(151);

    obj.Display();

    return 0;
}