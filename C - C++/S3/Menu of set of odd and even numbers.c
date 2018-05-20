#include<stdio.h>

void main()
{
    int i,n,op;
    printf("Enter limit of numbers\n");
    scanf("%d",&n);
    printf("Select option\n");
    printf("1. Set of even numbers in limit\n");
    printf("2. Set of odd numbers in limit\n");
    scanf("%d",&op);
    for(i=1;i<=n;i=i+2)
    {
        if(op==1)
            printf("%d ",i+1);
        else if(op==2)
            printf("%d ",i);
        else
        {
             i=n;
             printf("Invalid option");
        }
    }
}
