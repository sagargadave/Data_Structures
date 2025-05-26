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
        void InsertLast(int No);
        void Display();
};

SinglyLL::SinglyLL()
{
    head = NULL;
}

void SinglyLL::Display()
{
    struct node * temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << "\n";
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

void SinglyLL::InsertLast(int No)
{
    struct node *temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    struct node *newNode = new node;  // allocate memory for new node

    newNode->data = No;
    newNode->next = NULL;

    temp->next = newNode;
}

int main()
{
    SinglyLL obj;

    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertFirst(51);
    
    obj.Display();

    obj.InsertLast(91);

    obj.Display();
    return 0;
}