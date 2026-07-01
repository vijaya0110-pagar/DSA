//singlly circularlink list
#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE first,PPNODE last,int no)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first=newn;
        *last=newn;
    }
    else 
    {
        newn->next=*first;
        *first=newn;
    }
    (*last)->next=*first;

}

void InsertLast(PPNODE first,PPNODE last,int no)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first=newn;
        *last=newn;                //@
    }
    else 
    {
       (*last)->next=newn;         //@
        *last=newn;               //@
    }
    (*last)->next=*first;
}

void DeleteFirst(PPNODE first,PPNODE last)
{
    PNODE temp=NULL;
    if((*first ) == NULL && (*last )==NULL)         //case 1
    {
        return;
    }
    else if(*first == *last)                           //case 2
    {
        free(*first);
        *first=NULL;
        *last=NULL;
    }
    else                                               //case 3
    {
        temp=*first;
        *first=(*first)->next;
        
        free(temp);
        (*last)->next=*first;
    }
   
}

void DeleteLast(PPNODE first,PPNODE last)
{
    PNODE temp=NULL;
    if((*first ) == NULL && (*last )==NULL)         //case 1
    {
        return;
    }
    else if(*first == *last)                           //case 2
    {
        free(*first);
        *first=NULL;
        *last=NULL;
    }
    else                                               //case 3
    {
        temp=*first;
        while(temp->next!=*last)
        {
            temp=temp->next;
        }
        free(*last);
        *last=temp;
        (*last)->next=*first;
    }

}

void Display(PNODE first,PNODE last)
{
    do
    {
        printf("| %d |-> ",first->data);
        first=first->next;
    } while (first!=last->next);
    printf("\n");
    
}

int Count(PNODE first,PNODE last)
{
    int iCount=0;
    do
    {
        iCount++;
        first=first->next;
    } while (first!=last->next);
    printf("\n");
    
    return iCount;
}

void InsertAtPos(PPNODE first,PPNODE last,int no,int pos)
{
    PNODE newn=NULL;
    PNODE temp=NULL;
    int isize=0;
    isize= Count(*first,*last);
    if((pos <1 )|| (pos > isize+1))
    {
        printf("invalid position");
        return;
    }
    if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos == isize+1)
    {
        InsertLast(first,last,no);
    }
    else
    {
        newn=(PNODE)malloc(sizeof(NODE));
        newn->data=no;
        newn->next=NULL;

        temp=*first;
        for(int icnt=1;icnt<pos-1;icnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}

void DeleteAtPos(PPNODE first,PPNODE last,int pos)
{
    PNODE temp=NULL;
    PNODE target=NULL;
    int i=0;
    int isize=0;
    isize= Count(*first,*last);
    if((pos <1 )|| (pos > isize))
    {
        printf("invalid position");
        return;
    }
    if(pos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(pos == isize)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp=*first;
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        target=temp->next;
        temp->next=target->next;
        free(target);
    }
}

int main()
{
    PNODE head=NULL;
    PNODE tail=NULL;              //@
    int iRet=0;
    InsertFirst(&head,&tail,51);
     InsertFirst(&head,&tail,21);
      InsertFirst(&head,&tail,11);

    Display(head,tail);
    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,121);
    InsertLast(&head,&tail,151);
    
    Display(head,tail);
    iRet=Count(head,tail);
    printf("Number of nodes: %d \n",iRet);

    DeleteFirst(&head,&tail);
    
    Display(head,tail);
    iRet=Count(head,tail);
    printf("Number of nodes: %d \n",iRet);

   DeleteLast(&head,&tail);
    
    Display(head,tail);
    iRet=Count(head,tail);
    printf("Number of nodes: %d \n",iRet);

    InsertAtPos(&head,&tail,201,3);\
    Display(head,tail);
    iRet=Count(head,tail);
    printf("Number of nodes: %d \n",iRet);

    DeleteAtPos(&head,&tail,3);
    Display(head,tail);
    iRet=Count(head,tail);
    printf("Number of nodes: %d \n",iRet);
    return 0;
}