#include<iostream>
using namespace std;

// node structure for Singly Linked List
struct node
{
    int data;
    struct node *next;
};

// Class for Singly Linked List
class SinglyLL
{
    private :
    struct node * head;

    public :
        SinglyLL();                          // Constructor
        void InsertFirst(int no);            // Insert node at the beginning 
        void InsertLast(int no);             // Insert node at the Last
        void InsertAtPos(int pos, int no);   // Insert node at Position

        void Display();                      // Display all nodes
        int Count();                         // Count the number of nodes

        void DeleteFirst();                  // Delete first node
        void DeleteLast();                   // Delete last node 
        void DeleteAtPos(int pos);           // Delete node at a given position
};

SinglyLL::SinglyLL()
{
    head = nullptr;
}

int SinglyLL::Count()
{
    int cnt = 0;

    struct node * temp = head;

    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    
    return cnt;
}

void SinglyLL:: Display()
{
    struct node *temp = head;

    while(temp != nullptr)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;

}

void SinglyLL::InsertFirst(int no) 
{
    struct node *newNode = new node;

    newNode->data = no;
    newNode->next = nullptr;

    if(head == nullptr)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }

}

void SinglyLL::InsertLast(int no) 
{

}

void SinglyLL::InsertAtPos(int pos,int no) 
{

}

void SinglyLL::DeleteFirst()
{

}

void SinglyLL::DeleteLast()
{
    
}

void SinglyLL::DeleteAtPos(int pos)
{
    
}

// Main function
int main() 
{
    SinglyLL sll;

    sll.InsertFirst(11);
    sll.InsertFirst(21);
    sll.InsertFirst(51);

    sll.Display();
    
    int count = sll.Count();

    cout<<"Number of elements in Linked List is : "<<count<<endl;

    return 0;
}