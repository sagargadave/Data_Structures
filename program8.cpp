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
        void DeleteFirst();
        void DeleteLast();
        void DeleteatPos(int pos);
        int count();
};

SinglyLL::SinglyLL()
{
    head = NULL;
}

int SinglyLL:: count()
{
   struct node * temp = head;
    int count = 0;

   while(temp != NULL)
   {
        temp = temp->next;
        count++;
   }

   return count;
}

void SinglyLL::Display()
{
    struct node * temp = head;
    if(head == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    
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

void SinglyLL::InsertatPos(int Pos, int No)
{
    int count1 = count();

    if(count1 == 0 || Pos == count1)
    {
        InsertLast(No);
    }
    else if(Pos == count1+1)
    {
        cout<<"Enter a valid postion \n";
        return;
    }
    else if(Pos == 1)
    {
        InsertFirst(No);
    }
    else
    {
        struct node *newNode = new node;

        newNode->data = No;
        newNode->next = NULL;

        struct node *temp = head;

        for(int i=1; i <= count1; i++)
        {
            temp = temp->next;

            if(i== Pos-2)
            {
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
        }
    }
}

void SinglyLL:: DeleteFirst()
{
    struct node * temp = head;
    head = head->next;
    delete temp;
}

void SinglyLL:: DeleteLast()
{
    struct node * temp = head;

    if(temp->next == NULL)
    {        
        head = head->next;        
        delete temp;
        return;
    }
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;

    return;
}

void SinglyLL :: DeleteatPos(int pos)
{
    int count1 = this->count();

    if(pos == 1)
    {
        DeleteFirst();
        return;
    }
    else if(pos == count1)
    {
        DeleteLast();
        return;
    }
    else if(pos == 0 || pos >= count1+1)
    {
        cout<<"Enter a valid Position \n";
        return;
    }
    else
    {
        struct node *temp = head;

        for(int i = 1; i<pos-1; i++)
        {
            temp = temp->next;
        }

        struct node *temp1 = temp->next;
        temp->next = temp->next->next;
        delete temp1;
    }
}

int main()
{
    SinglyLL obj;

    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertFirst(51);
    obj.InsertFirst(101);
    obj.InsertFirst(121);

    obj.Display();

    cout<<"Number of elements are : "<<obj.count()<<"\n";

    obj.DeleteatPos();

    obj.Display();

    cout<<"Number of elements are : "<<obj.count()<<"\n";

    return;
}