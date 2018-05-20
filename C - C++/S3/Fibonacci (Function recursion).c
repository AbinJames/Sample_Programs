#include<stdio.h>
void fibonacci(int a,int b,int c,int d);
void main()
{
    int f;
    char c;
    do
    {
            printf("Enter the number of elements in series\n");
            scanf("%d",&f);
            printf("The fibonacci series is \n");
            fibonacci(f,1,0,1);
            printf("\nDo you wish to enter again ? (y/n)\n");
            fflush(stdin);
            scanf("%c",&c);
    }
    while(c=='Y'||c=='y');
}
void fibonacci(int a,int b,int c,int d)
{
    if (d<=a)
    {
        printf("%d ",c);
        fibonacci(a,c,b+c,d+1);
    }
}

