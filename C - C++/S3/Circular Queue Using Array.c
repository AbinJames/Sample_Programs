#include<stdio.h>

void traverse(int q[],int front,int rear)
{
    printf("The queue is\n");
    if(front==-1)
        return;
    while(front!=rear)
    {
        printf("%5d",q[front]);
        front=(front+1)%5;
    }
    printf("%5d",q[front]);
    printf("\n");
}

int checkfull(int front,int rear)
{
    if(front==(rear+1)%5)
        return(1);
    return(0);
}

int checkempty(int front)
{
    if(front==-1)
        return(1);
    return(0);
}

void push(int q[],int * front,int * rear)
{
    *rear=(*rear+1)%5;
    if(*front==-1)
        *front=*rear;
    printf("Enter value\n");
    scanf("%d",&q[*rear]);

}

int pop(int q[],int * front,int * rear)
{
    int n;
    n = q[*front];
    if(*front==*rear)
    {
        *front=-1;
        *rear=-1;
    }
    else
        *front=(*front+1)%5;
    return(n);
}

void main()
{
    int front=-1,rear=-1,q[5],op,con=0,ele;
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
            if(!checkfull(front,rear))
                push(q,&front,&rear);
            else
                printf("Queue is full\n");
            traverse(q,front,rear);
            break;
        case 2:
            if(!checkempty(front))
            {
                ele = pop(q,&front,&rear);
                printf("Deleted element : %d\n",ele);
            }
            else
                printf("Queue is empty\n");
            traverse(q,front,rear);
            break;
        case 3:
            traverse(q,front,rear);
            break;

        }
        printf("Enter 0 to continue (Else 1)\n");
        scanf("%d",&con);
    }

}
