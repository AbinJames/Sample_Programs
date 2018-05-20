#include<stdio.h>
void swap1(int,int);
void swap2(int *,int *);
void main()
{
    int a,b;
    char c;
    do
    {
        printf("Enter two numbers\n");
        scanf("%d%d",&a,&b);
        printf("CALL BY VALUE\n");
        printf("BEFORE SWAP\n");
        printf("a = %d\nb = %d\n",a,b);
        swap1(a,b);
        printf("AFTER SWAP\n");
        printf("a = %d\nb = %d\n",a,b);
        printf("CALL BY REFERENCE\n");
        printf("BEFORE SWAP\n");
        printf("a = %d\nb = %d\n",a,b);
        swap2(&a,&b);
        printf("AFTER SWAP\n");
        printf("a = %d\nb = %d\n",a,b);
        printf("\nDo you wish to enter again ? (Y/N)\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c=='Y'||c=='y');
}
void swap1(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void swap2(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
