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
    node* head;

public:
    DoublyLL();                    // Constructor
    void InsertFirst(int no);     // Insert at the beginning
};

// Constructor
DoublyLL::DoublyLL() 
{
    head = nullptr;
}

// Insert a node at the beginning
void DoublyLL::InsertFirst(int no) 
{
    node* newNode = new node(no);

    if (head != nullptr) 
    {
        newNode->next = head;
        head->prev = newNode;
    }

    head = newNode;
}

// Main function
int main() 
{
    DoublyLL dll;

    dll.InsertFirst(30);
    dll.InsertFirst(20);
    dll.InsertFirst(10);

    return 0;
}