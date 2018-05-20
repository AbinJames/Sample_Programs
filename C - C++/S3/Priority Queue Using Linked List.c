#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int num;
    struct queue * link;
};

void traverse(struct queue *front [],struct queue * rear[])
{
    printf("The queue is\n");
    int i;
    printf(" Front  Back\n");
    for(i=1; i<5; i++)
    {
        printf("%5u %5u",front[i],rear[i]);
        if(front[i] != NULL)
        {
            while(rear[i]!=front[i])
            {
                printf("%5d",front[i]->num);
                front[i] = front[i]->link;
            }
            printf("%5d",front[i]->num);
        }
        printf("\n");
    }

}

void push(struct queue *front [],struct queue * rear[])
{
    struct queue * node;
    node = (struct queue *)malloc(sizeof(struct queue));
    if(node==NULL)
    {
        printf("Memory is full \n");
        return;
    }
    int pri;
    printf("Enter value\n");
    printf("Number : ");
    scanf("%d",&node->num);
    printf("Priority : ");
    scanf("%d",&pri);
    node->link=NULL;
    if(front[pri]==NULL)
        front[pri]=node;
    else
        rear[pri]->link=node;
    rear[pri]=node;
    rear[pri]->link=front[pri];
}

int isempty(struct queue *front [],struct queue * rear[])
{
    int i;
    for(i=0; i<5; i++)
    {
        if(front[i] != NULL)
            return(i);
    }
    return(0);
}

int pop(struct queue *front [],struct queue * rear[],int pri)
{
    int n;
    struct queue * node;
    n = front[pri]->num;
    node=front[pri];
    if(front[pri]->link==front[pri])
    {
        front[pri]=NULL;
        rear[pri]=NULL;
    }
    else
    {
        front[pri]=front[pri]->link;
        rear[pri]->link=front[pri];
    }
    free(node);
    return(n);
}

void main()
{
    struct queue * front[5]= {NULL,NULL,NULL,NULL,NULL,NULL},* rear[5]= {NULL,NULL,NULL,NULL,NULL,NULL};
    int op=1,ele,pri;
    while(op != 4)
    {
        printf("Select option\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            push(front,rear);
            traverse(front,rear);
            break;
        case 2:
            pri = isempty(front,rear);
            if(pri != 0)
            {
                ele = pop(front,rear,pri);
                printf("Deleted element : %d\n",ele);
                traverse(front,rear);
            }
            else
                printf("Queue is empty\n");
            break;
        case 3:
            traverse(front,rear);
            break;
        case 4:
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }

}
