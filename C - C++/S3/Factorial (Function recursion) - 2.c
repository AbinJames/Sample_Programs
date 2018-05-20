#include<stdio.h>
int factorial(int a);
void main()
{
    int f,r;
    char c;
    do
    {
        printf("Enter the number\n");
        scanf("%d",&f);
        r=factorial(f);
        printf("The Factorial is %d\n",r);
        printf("Do you wish to enter again ? (y/n)\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c=='Y'||c=='y');
}
int factorial(int a)
{
    if(a==0)
        return 1;
    else if (a==1)
        return a;
    else
        return a*factorial(a-1);
}
