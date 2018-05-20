#include<stdio.h>
void recursion(int a,int b,int c);
void main()
{
    int f;
    printf("Enter the number\n");
    scanf("%d",&f);
    recursion(1,1,f);
}
void recursion(int a,int b,int c)
{
    if (b<=c)
    {
        a=a*b;
        recursion(a,b+1,c);
    }
    if(b==c)
    printf("The factorial is %d\n",a);
}
