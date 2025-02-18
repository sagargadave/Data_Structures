#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Display(PNODE First)
{
    while(First != NULL)
    {
        printf("| %d |<=>",First->data);
        First = First->next;
    }
    printf("NULL\n");
}

int Count(PNODE First)
{
    int cnt = 0;

    while(First != NULL)
    {
        cnt++;
        First = First->next;
    }
    return cnt;
}

void InsertFirst(PPNODE First,int data)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        (*First)->prev = newn;

        *First = newn;
    }
}

void InsertAtLast(PPNODE First,int data)
{
    PNODE temp = *First;

    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}

void InsertAtPos(PPNODE First,int data,int pos)
{
    if(pos >Count(*First)+1 || pos < 0)
    {
        printf("Invalid Postion \n");
    }
    else if(pos == 1)
    {
        InsertFirst(First,data);
    }
    else if(pos == Count(*First)+1)
    {
        InsertAtLast(First,data);
    }
    else
    {
        PNODE temp = *First;

        PNODE newn = (PNODE)malloc(sizeof(NODE));

        newn->data = data;
        newn->next = NULL;
        newn->next = NULL;

        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
}

int main()
{
    PNODE Head = NULL;

    InsertFirst(&Head,11);
    InsertFirst(&Head,21);
    InsertFirst(&Head,51);

    Display(Head);

    InsertAtLast(&Head,100);
    InsertAtLast(&Head,200);
    InsertAtLast(&Head,300);

    Display(Head);

    printf("Number of elements in Linked List : %d\n",Count(Head));

    InsertAtPos(&Head,400,2);

    Display(Head);

    printf("Number of elements in Linked List : %d\n",Count(Head));
    
    InsertAtPos(&Head,500,1);
    Display(Head);

    printf("Number of elements in Linked List : %d\n",Count(Head));

    InsertAtPos(&Head,600,6);
    Display(Head);

    printf("Number of elements in Linked List : %d\n",Count(Head));

    InsertAtPos(&Head,700,7);

    Display(Head);

    printf("Number of elements in Linked List : %d\n",Count(Head));

    InsertAtPos(&Head,800,11);

    Display(Head);

    printf("Number of elements in Linked List : %d\n",Count(Head));

    return 0;
}