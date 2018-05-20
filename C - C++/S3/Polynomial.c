#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef,pow;
    struct node * link;
};
void traverse(struct node * nptr)
{

    while(nptr!=NULL)
    {
        if(nptr->pow!=0)
            printf("%dx^%d + ",nptr->coef,nptr->pow);
        else
            printf("%dx^%d ",nptr->coef,nptr->pow);
        nptr=nptr->link;
    }
}

struct node * createfirst()
{
    struct node * nodeptr;
    nodeptr=(struct node *)malloc(sizeof(struct node));
    if(nodeptr==NULL)
    {
        printf("Memory Full\n");
    }
    else
    {
        printf("Enter first coeffecient\n");
        scanf("%d",&nodeptr->coef);
        printf("Enter first power\n");
        scanf("%d",&nodeptr->pow);
        nodeptr->link=NULL;
        return(nodeptr);
    }
}

void create(struct node ** end)
{
    struct node * nodeptr;
    do
    {
        nodeptr=(struct node *)malloc(sizeof(struct node));
        if(nodeptr==NULL)
        {
            printf("Memory Full\n");
            return;
        }
        printf("Enter coeffecient\n");
        scanf("%d",&nodeptr->coef);
        if(nodeptr->coef!=0)
        {
            printf("Enter power\n");
            scanf("%d",&nodeptr->pow);
            nodeptr->link=NULL;
            (*end)->link=nodeptr;
            *end=nodeptr;
        }
    }while(nodeptr->coef!=0);
}

void add(struct node * start1,struct node * start2,struct node ** start3,struct node ** end3)
{
        while(start1!=NULL && start2!=NULL)
        {
            struct node * nodeptr;
            nodeptr=(struct node *)malloc(sizeof(struct node));
            if(start1->pow==start2->pow)
            {
                nodeptr->coef = (start1->coef) + (start2->coef);
                nodeptr->pow=start1->pow;
                start1=start1->link;
                start2=start2->link;
            }
            else if(start1->pow > start2->pow)
            {
                nodeptr->coef = start1->coef;
                nodeptr->pow = start1->pow;
                start1=start1->link;
            }
            else
            {
                nodeptr->coef=start2->coef;
                nodeptr->pow=start2->pow;
                start2=start2->link;
            }
            nodeptr->link=NULL;
            if(*start3==NULL)
            {

                *start3=nodeptr;
                *end3 = nodeptr;
            }
            else
            {
                (*end3)->link=nodeptr;
                *end3 = nodeptr;
            }
        }
        if(start1!=NULL)
        {
            while(start1!=NULL)
            {
                struct node * nodeptr;
                nodeptr=(struct node *)malloc(sizeof(struct node));
                nodeptr->coef = start1->coef;
                nodeptr->pow = start1->pow;
                nodeptr->link=NULL;
                start1=start1->link;
                (*end3)->link=nodeptr;
                *end3 = nodeptr;
            }
        }
        if(start2!=NULL)
        {
            while(start2!=NULL)
            {
                struct node * nodeptr;
                nodeptr=(struct node *)malloc(sizeof(struct node));
                nodeptr->coef = start2->coef;
                nodeptr->pow = start2->pow;
                nodeptr->link=NULL;
                start2=start2->link;
                (*end3)->link=nodeptr;
                *end3 = nodeptr;
            }
        }
}

void main()
{
    struct node * start1=NULL,*start3=NULL,*start2=NULL,*end1,*end2,*end3=NULL;
    printf("Enter first polnymial\n");
    start1 = createfirst();
    end1=start1;
    create(&end1);
    printf("\nThe first polynomial is \n");
    traverse(start1);

    printf("\nEnter second polnymial\n");
    start2 = createfirst();
    end2 = start2;
    create(&end2);
    printf("\nThe second polynomial is \n");
    traverse(start2);

    printf("\n\nFirst  : ");
    traverse(start1);

    printf("\nSecond : ");
    traverse(start2);

    add(start1,start2,&start3,&end3);
    printf("\nResult : ");
    traverse(start3);
}
