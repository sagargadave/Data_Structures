#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class SinglyLL
{
    private:
        struct node *head;

    public:
        SinglyLL();              // Constructor
        void InsertFirst(int No);
        void Display();   
};

SinglyLL::SinglyLL()
{
    head = NULL;
}

void SinglyLL::InsertFirst(int No)
{
    node* newNode = new node;   // allocate memory for new node

    newNode->data = No;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void SinglyLL::Display()
{
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    SinglyLL obj;

    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertFirst(51);

    cout << "Linked List: ";
    obj.Display();

    return 0;
}
