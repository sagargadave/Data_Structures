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
        void InsertatPos(int pos, int No);
        void count();
};

SinglyLL::SinglyLL()
{
    head = NULL;
}

void SinglyLL:: count()
{
   struct node * temp = head;
    int count = 0;

   while(temp != NULL)
   {
        temp = temp->next;
        count++;
   }

   cout<<"Number of elements are : "<<count<<"\n";
}

void SinglyLL::Display()
{
    struct node * temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void SinglyLL::InsertFirst(int No)
{
    struct node* newNode = new node;   // allocate memory for new node

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

    struct node *newNode = new node;

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
    obj.count();

    obj.InsertLast(91);

    obj.Display();
    obj.count();

    return 0;
}