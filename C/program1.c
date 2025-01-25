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
    printf("Elements of LinkedList : \n");

    while(first!= NULL)
    {
        printf("%d->",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

void InsertFirst(PPNODE first,int Number)
{
    printf("\n");
    printf("first : %d\n",first);
    printf("*first : %d\n",*first);
    // printf("**first : %d\n",**first);
    printf("&first : %d\n",&first);


    printf("\n");

    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = Number;
    newn->next = NULL;

    printf("newn:%d\n",newn);
    printf("*newn:%d\n",*newn);
    printf("&newn:%d\n",&newn);

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
    printf("\n");

    printf("first : %d\n",first);
    printf("*first : %d\n",*first);
    printf("**first : %d\n",**first);
    printf("&first : %d\n",&first);

}

int main()
{
    PNODE Head = NULL;

    printf("Head: %d\n",Head);
    printf("&Head: %d\n",&Head);

    InsertFirst(&Head,21);

    printf("\n");

    printf("Head: %d\n",Head);
    printf("&Head: %d\n",&Head);
    printf("*Head: %d\n",*Head);

    printf("\n");

    printf("Head: %d\n",Head);
    printf("&Head: %d\n",&Head);

    InsertFirst(&Head,11);

        printf("\n");

    printf("Head: %d\n",Head);
    printf("&Head: %d\n",&Head);
    printf("*Head: %d\n",*Head);

    // InsertFirst(&Head,51);

    // Display(Head);

    return 0;
}