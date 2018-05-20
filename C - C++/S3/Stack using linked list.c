#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node * link;
};

void traverse(struct node * nptr)
{
    printf("The list is now \n");
    while(nptr!=NULL)
    {

        printf("%d\n",nptr->num);
        nptr=nptr->link;
    }
}

struct node * push(struct node **top)
{
    struct node * nodeptr;
    nodeptr=(struct node *)malloc(sizeof(struct node));
    if(nodeptr==NULL)
        printf("Memory Full\n");
    else
    {
        printf("Enter number\n");
        scanf("%d",&nodeptr->num);
        nodeptr->link= *top;
        *top=nodeptr;
    }
}

int isempty(struct queue * top)
{
    if(top==NULL)
        return(1);
    return(0);
}

int pop(struct node **top)
{
    int n;
    struct node * nd = *top;
    n = (*top) -> num;
    *top = (*top)->link;
    free(nd);
    return(n);
}

void main()
{
    struct node * top=NULL;
    int op,con=0,elem;
    while(con==0)
    {
        printf("select option\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            push(&top);
            break;
        case 2:
            if(!isempty(top))
            {
                elem = pop(&top);
                printf("deleted element : %d\n",elem);
            }
            else
                printf("The list is empty\n");
            break;
        case 3:
            traverse(top);
            break;
        case 4:
            exit(0);
        default :
            printf("Invalid option\n");
            break;
        }
        printf("Enter 0 to continue\n");
        scanf("%d",&con);
    }

}

