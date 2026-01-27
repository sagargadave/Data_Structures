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
    if(head == nullptr)
    {
        cout<<"Linked List is Empty \n";
    }
    else
    {
        node *temp = head;

        do{
            cout<<temp->data<<"->";
            temp = temp->next;
        }while(temp != head);

        cout<<"\n";
    }
}

int SinglyCircular :: Count()
{
    if(head == nullptr)
    {
        return 0;
    }
    else
    {
        node *temp = head;
        int count = 0;

        do{
            count++;
            temp = temp->next;
        }while(temp != head);

        return count;
    }

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
    if(head == nullptr)
    {
        InsertFirst(no);
    }
    else
    {
        node *newNode = new node;

        newNode->data = no;
        newNode->next = head;

        tail->next = newNode;
        tail = newNode;
    }
}
    
void SinglyCircular :: InsertAtPos(int no, int Pos)
{    
    int size = this->Count();

    if(Pos < 1 || Pos > size+1)
    {
        cout<<"Enter a valid position\n";
        return;
    }
    else if(Pos == 1)
    {
        InsertFirst(no);
    }
    else if(Pos == size+1)
    {
        InsertLast(no);
    }
    else
    {
        node *temp = head;
        node *newNode = new node;
        newNode->data = no;

        for(int i = 1; i < Pos-1; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void SinglyCircular :: DeleteFirst()
{
    if(head == nullptr)
        return;
    else if(head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        node *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }
}


void SinglyCircular :: DeleteLast()
{
    if(head == nullptr)
        return;
    else if(head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        node *temp = head;

        while(temp->next->next != head)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = head;
        tail = temp;
    }

}

void SinglyCircular :: DeleteAtPos(int Pos)
{
    int size = this->Count();

    if(Pos < 1 || Pos > size)
    {
        cout<<"Enter a valid position\n";
        return;
    }
    else if(Pos == 1)
    {
        DeleteFirst();
    }
    else if(Pos == size)
    {
        DeleteLast();
    }
    else
    {
        node *temp1 = head;

        for(int i = 1; i < Pos-1; i++)
        {
            temp1 = temp1->next;
        }

        node *temp2 = temp1->next;
        temp1->next = temp2->next;

        delete temp2;
    }    
}

int main()
{
    SinglyCircular obj;

    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertFirst(51);

    obj.Display();
    
    int count = obj.Count();
    cout<<"Number of elements in Linked List : "<<count<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(151);

    obj.Display();

    count = obj.Count();
    cout<<"Number of elements in Linked List : "<<count<<"\n";

    obj.InsertAtPos(7,7);

    obj.Display();    

    count = obj.Count();
    cout<<"Number of elements in Linked List : "<<count<<"\n";
    
    obj.DeleteFirst();

    obj.Display();    

    count = obj.Count();
    cout<<"Number of elements in Linked List : "<<count<<"\n";

    obj.DeleteLast();
 
    obj.Display();    

    count = obj.Count();
    cout<<"Number of elements in Linked List : "<<count<<"\n";

    obj.DeleteAtPos(4);
    
    obj.Display();    

    count = obj.Count();
    cout<<"Number of elements in Linked List : "<<count<<"\n";

    return 0;
}