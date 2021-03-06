#include<stdio.h>

struct queue
{
    int num;
    struct queue * link;
};

void traverse(struct queue * front)
{
    printf("The queue is\n");
    while(front!=NULL)
    {
        printf("%5d",front->num);
        front = front->link;
    }
    printf("\n");
}

void push(struct queue ** front,struct queue ** rear)
{
    struct queue * node;
    node = (struct queue *)malloc(sizeof(struct queue));
    if(node==NULL)
    {
        printf("Memory is full \n");
        return;
    }
    printf("Enter value\n");
    scanf("%d",&node->num);
    node->link=NULL;
    if(*front==NULL)
        *front=node;
    else
        (*rear)->link=node;
    *rear=node;
}

int isempty(struct queue * front)
{
    if(front==NULL)
        return(1);
    return(0);
}
int pop(struct queue ** front,struct queue ** rear)
{
    int n;
    struct queue * node;
    n = (*front)->num;
    node=*front;
    if((*front)->link==NULL)
    {
        *front=NULL;
        *rear=NULL;
    }
    else
        *front=(*front)->link;
    free(node);
    return(n);
}

void main()
{
    struct queue * front=NULL,*rear=NULL;
    int op,con=0,ele;
    while(con==0)
    {
        printf("Select option\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            push(&front,&rear);
            traverse(front);
            break;
        case 2:
            if(!isempty(front))
            {
                ele = pop(&front,&rear);
                printf("Deleted element : %d\n",ele);
            }
            else
                printf("Queue is empty\n");
            traverse(front);
            break;
        case 3:
            traverse(front);
            break;

        }
        printf("Enter 0 to continue (Else 1)\n");
        scanf("%d",&con);
    }

}

