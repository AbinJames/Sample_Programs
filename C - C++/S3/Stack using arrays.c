#include<stdio.h>
void display(int a[],int top)
{
    int i;
    for(i=top;i>=0;i--)
        printf("%d\n",a[i]);
}

void push(int a[],int *top,int c)
{
    if(*top==c-1)
        printf("the stack is full\n");
    else
    {
        (*top)++;
        printf("Insert value\n");
        scanf("%d",&a[*top]);
    }

}

int isempty(int top)
{
    if(top==-1)
        return(1);
    return(0);
}

int pop(int a[],int * top)
{
    int n;
    n = a[*top];
    (*top)--;
    return(n);
}

void main()
{
    int arr[5],top=-1,op,con=0,elem;
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
            push(arr,&top,5);
            break;
        case 2:
            if(!isempty(top))
            {
                elem = pop(arr,&top);
                printf("Deleted element : %d\n",elem);
            }
            else
                printf("The list is empty\n");
            break;
        case 3:
            printf("The stack is\n");
            display(arr,top);
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
