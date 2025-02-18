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

void Display(PNODE First)
{
    if(First == NULL)
    {
        printf("Linked List is empty");
        return;
    }

    PNODE temp = First;

    printf("Elements of Linked List are : \n");

    do
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }while(temp != First);

    printf("\n");
}

int Count(PNODE First)
{
    int cnt = 0;

    PNODE temp = First;

    do{
        cnt++;
        temp = temp->next;
    }while(temp != First);

    return cnt;
}

void InsertFirst(PPNODE First,PPNODE Last, int data)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = data;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
        newn->next = *First;
        *First = newn;
    }

    (*Last)->next = *First;
}

void InsertAtLast(PPNODE First, PPNODE Last, int data)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = data;
    newn->next = NULL;

    if(*First == NULL && *Last == NULL)
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
        (*Last)->next = newn;
        *Last = newn;
    }
    (*Last)->next = *First;
}

void InsertAtPos(PPNODE First, PPNODE Last, int data,int pos)
{
    if(pos > Count(*First)+1 || pos < 0)
    {
        printf("Invalid Position\n");
        return;
    }
    else if(pos == Count(*First)+1)
    {
        InsertAtLast(First,Last,data);        
    }
    else if(pos == 1)
    {
        InsertFirst(First,Last,data);
    }
    else
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));
        newn->data = data;
        newn->next = NULL;

        PNODE temp = *First;

        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;        
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE First,PPNODE Last)
{
    if(*First == NULL)
    {
        printf("Linked List is empty\n");
    }
    else if((*First)->next == *Last)
    {
        free(*First);
        free(*Last);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        PNODE temp = *First;
        *First=(*First)->next;
        free(temp);
        (*Last)->next = *First;
    }
}

void DeleteLast(PPNODE First, PPNODE Last)
{
    if(*First == NULL)
    {
        printf("LL is empty \n");
    }
    else
    {        
        PNODE temp = *First;

        while(temp->next->next != *First)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = *First;
        *Last = temp;
    }
}

void DeleteAtPos(PPNODE First,PPNODE Last,int pos)
{
    if(pos > Count(*First) || pos < 0)
    {
        printf("Invalid Postion \n");        
    }
    else if(pos == Count(*First))
    {
        DeleteLast(First,Last);
    }
    else if(pos == 1)
    {
        DeleteFirst(First,Last);
    }
    else
    {
        PNODE temp = *First;

        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }
        PNODE temp1 = temp->next;
        temp->next = temp->next->next;
        free(temp1);
    }
}

int main ()
{
    PNODE Head = NULL;
    PNODE Tail = NULL;

    InsertFirst(&Head,&Tail,11);
    InsertFirst(&Head,&Tail,21);
    InsertFirst(&Head,&Tail,51);

    Display(Head);

    int cnt = Count(Head);

    printf("Number of elements in LinkedList : %d\n",cnt);

    InsertAtLast(&Head,&Tail,99);
    InsertAtLast(&Head,&Tail,101);
    InsertAtLast(&Head,&Tail,200);

    Display(Head);

    cnt = Count(Head);

    printf("Number of elements in LinkedList : %d\n",cnt);

    InsertAtPos(&Head,&Tail,50,3);

    Display(Head);

    cnt = Count(Head);

    printf("Number of elements in LinkedList : %d\n",cnt);

    InsertAtPos(&Head,&Tail,70,2);

    Display(Head);

    cnt = Count(Head);

    printf("Number of elements in LinkedList : %d\n",cnt);
    
    // InsertAtPos(&Head,&Tail,70,8);
    // DeleteLast(&Head,&Tail);

    DeleteAtPos(&Head,&Tail,4);
    Display(Head);

    cnt = Count(Head);

    printf("Number of elements in LinkedList : %d\n",cnt);

    return 0;
}