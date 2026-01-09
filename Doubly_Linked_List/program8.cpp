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
    int count = 0;
    struct node * temp = head;
    
    while(temp != nullptr)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

void DoublyLL:: Display()
{
    struct node * temp = head;

    if(temp == nullptr)
    {
        cout<<"Linked List is Empty"<<"\n";
    }
    else
    {
        while(temp != nullptr)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }

        cout<<"null\n";
    }
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
    struct node * newNode = new node;

    if(head == nullptr)
    {
        cout<<"Linked List is Empty \n";
    }
    else
    {
        int count = Count();
        struct node * temp = head;

        if(pos == 1)
        {
            InsertFirst(no);
            return;
        }
        else if(pos == count)
        {
            InsertLast(no);
            return;            
        }
        else if(pos >= 2 && pos <= count-1)
        {
            for(int i=1; i<pos-1; i++)
            {
                temp = temp->next;
            }

            struct node *newNode = new node();
            newNode->data = no;
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        else
        {
            cout<<"Enter a Valid Postion\n";
        }
    }
}

void DoublyLL::DeleteFirst()
{
    if(head == nullptr)
    {
        cout<<"LL is empty \n";
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        delete temp;
    }
}

void DoublyLL::DeleteLast()
{
    struct node *temp = head;

    if(head == nullptr)
    {
        cout<<"LL is empty \n";
        return;
    }
    else if(head->next == nullptr)
    {
        head = head->next;
        delete temp;
    }
    else
    {
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        
        delete temp->next;
        temp->next = nullptr;
    }
}

void DoublyLL::DeleteAtPos(int pos)
{
    int count = Count();

    if(head == nullptr)    
    {
        cout<<"LL is empty"<<endl;
    }
    else if(pos == 1)
    {
        DeleteFirst();
        return;
    }
    else if(pos == count)
    {
        DeleteLast();
        return;
    }
    else if(pos>= 2 && pos<= count-1)
    {
        struct node * temp = head;

        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }

        struct node *temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
    }
    else
    {
        cout<<"Enter a valid Postion\n";
    }
}

// Main function
int main() 
{
    DoublyLL dll;

    dll.InsertFirst(1);
    dll.InsertFirst(2);
    dll.InsertFirst(3);
    dll.InsertFirst(4);

    dll.Display();

    dll.InsertLast(5);
    dll.InsertLast(6);
    dll.InsertLast(7);
    dll.InsertLast(8);
    dll.InsertLast(9);

    dll.Display();

    int elements = dll.Count();

    cout<<"Number of elements in Linked List = "<<elements<<"\n";

    dll.InsertAtPos(7,100);

    dll.Display();

    elements = dll.Count();

    cout<<"Number of elements in Linked List = "<<elements<<"\n";

    dll.DeleteFirst();

    dll.Display();

    elements = dll.Count();

    cout<<"Number of elements in Linked List = "<<elements<<"\n";

    dll.DeleteLast();

    dll.Display();

    elements = dll.Count();

    cout<<"Number of elements in Linked List = "<<elements<<"\n";

    dll.DeleteAtPos(7);

    dll.Display();

    elements = dll.Count();

    cout<<"Number of elements in Linked List = "<<elements<<"\n";

    return 0;
}