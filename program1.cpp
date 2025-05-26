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

int main()
{
    SinglyLL obj;

    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertFirst(51);
    
    return 0;
}
