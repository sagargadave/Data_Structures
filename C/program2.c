#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Display(PNODE first)
{

    if(first == NULL)
    {
        printf("Linked List is empty \n");
        return;
    }

    printf("Elements of Linkedlist are :\n");

    while(first != NULL)
    {
        printf("%d->",first->data);
        first=first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int cnt = 0;

    while(first != NULL)
    {
        cnt = cnt + 1;
        first = first->next;
    }

    return cnt;
}

void InsertAtLast(PPNODE Last, int data)
{
    PNODE newNode = (PNODE)malloc(sizeof(NODE));

    newNode->data = data;
    newNode->next = NULL;

    if(*Last == NULL)
    {
        *Last = newNode;
    }
    else
    {
        PNODE temp = *Last;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void DeleteLast(PPNODE first)
{
    if(*first == NULL)
    {
        printf("Linked List is empty \n");
        return;
    }
    else if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        PNODE temp = *first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }    
}

void InsertFirst(PPNODE elemnt, int data)
{
    PNODE newNode = (PNODE)malloc(sizeof(NODE));

    newNode->data = data;
    newNode->next = NULL;

    if(*elemnt == NULL)
    {
        *elemnt = newNode;
    }
    else
    {
        newNode->next = *elemnt;
        *elemnt = newNode;
    }
}

void InsertAtPos(PPNODE first, int data,int pos)
{
    if(pos >= Count(*first)+1)
    {
        InsertAtLast(first,data);
    }
    else if(pos == 1)
    {
        InsertFirst(first,data);
    }
    else if(pos <= Count(*first) && pos>1)
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));

        newn->data = data;
        newn->next = NULL;

        PNODE temp = *first;//100

//temp = 200
//2node = 200
//3node = 300
//newn = 900

        for(int i = 1; i<pos-1; i++)
        {
            temp = temp->next;//200
        }
        newn->next = temp->next;//300
        temp->next = newn;//500
    }
    else
    {
        printf("Invalid  Postion \n");
        return;
    }
}

void DeleteFirst(PPNODE first)
{
    if(*first == NULL)
    {
        printf("Unable to delete as Linked list is empty");
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        PNODE temp = *first;
        *first = (*first) -> next;
        free(temp);
    }
}

void DeleteAtPos(PPNODE first,int pos)
{
    if(pos > Count(*first) || pos < 0)
    {
        printf("Invalid Pos");
        return;
    }
    else if(pos == Count(*first))
    {
        DeleteLast(first);
    }
    else if(pos == 1)
    {
        DeleteFirst(first);
    }
    else
    {
        PNODE temp = *first;

        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }

        PNODE temp2 = temp->next;

        temp -> next = temp->next->next;

        free(temp2);
    }
}

int main()
{
    int cnt = 0;

    PNODE Head = NULL;

    cnt = Count(Head);

    printf("Number of elements in a Linked List : %d\n",cnt);


    InsertFirst(&Head,1);
    InsertFirst(&Head,2);
    InsertFirst(&Head,3);
    InsertFirst(&Head,4);
    InsertFirst(&Head,5);

    Display(Head);

    cnt = Count(Head);

    printf("Number of elements in a Linked List : %d\n",cnt);

    InsertAtLast(&Head,6);
    InsertAtLast(&Head,7);
    InsertAtLast(&Head,8);

    Display(Head);

    cnt = Count(Head);

    printf("Number of elements in a Linked List : %d\n",cnt);
    
    DeleteLast(&Head);
    DeleteLast(&Head);
    DeleteLast(&Head);
    DeleteLast(&Head);

    Display(Head);
    
    cnt = Count(Head);

    printf("Number of elements in a Linked List : %d\n",cnt);

    InsertAtPos(&Head,900,5);

    Display(Head);
    
    cnt = Count(Head);

    printf("Number of elements in a Linked List : %d\n",cnt);

    // DeleteFirst(&Head);

    DeleteAtPos(&Head,4);

    Display(Head);
    
    cnt = Count(Head);

    printf("Number of elements in a Linked List : %d\n",cnt);

    return 0;
}