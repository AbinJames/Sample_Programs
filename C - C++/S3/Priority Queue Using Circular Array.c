#include<stdio.h>

void display(int arr[][5],int fb [][2])
{
    int i,front,back;
    printf("The queue is \n");
    printf(" Front  Back\n");
    for(i=1;i<5;i++)
    {
        front = fb[i][0];
        back = fb[i][1];
        printf("%5d%5d",front,back);
        if(front!=-1)
        {
            while(front != back)
            {
                printf("%5d",arr[i][front]);
                front = (front+1)%5;
            }
            printf("%5d",arr[i][front]);
        }
        printf("\n");
    }
}

int isfull(int front , int back)
{
    if(front == (back+1)%5)
        return(1);
    return(0);
}


void insert(int arr[][5], int fb[5][2])
{
    int num, pri;
    printf("Enter value\n");
    printf("Number : ");
    scanf("%d",&num);
    printf("Priority : ");
    scanf("%d",&pri);
    if(!isfull(fb[pri][0],fb[pri][1]))
    {
        fb[pri][1] = (fb[pri][1] + 1) % 5;
        if(fb[pri][0]==-1)
            fb[pri][0]=0;
        arr[pri][fb[pri][1]] = num;
    }
    else
        printf("The queue is full\n");
}

int isempty(int fb[][2])
{
    int i;
    for(i=0;i<5;i++)
    {
        if(fb[i][0]!=-1)
            return(i);
    }
    return(0);
}

int delque(int arr[5][5],int fb[][2],int pri)
{
    int num;
    num = arr[pri][fb[pri][0]];
    if(fb[pri][0] == fb[pri][1])
    {
        fb[pri][0] = -1;
        fb[pri][1] = -1;
    }
    else
        fb[pri][0] = (fb[pri][0] +1)%5;
    return (num);
}
void main()
{
    int arr[5][5],fb[5][2]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},n,pri,op=1;
    while(op!=0)
    {
        printf("Select option\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("0. Exit\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            insert(arr,fb);
            display(arr,fb);
            break;
        case 2:
            pri = isempty(fb);
            if(pri != 0 )
            {
                n = delque(arr,fb,pri);
                printf("Deleted element : %d\n",n);
            }
            else
                printf("The queue is empty\n");
            display(arr,fb);
            break;
        case 0:
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }
}
