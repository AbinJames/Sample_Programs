#include<stdio.h>
void main()
{
    int a,b,c,*ip;
    printf("Address of variables");
    printf("\na = %u , b = %u , c= %u , ip = %u",&a,&b,&c,&ip);

    printf("\nInitial value of ip = %u",ip);
    printf("\nInitial value of a = %d",a);
    printf("\nInitial value of b = %d",b);
    printf("\nInitial value of a = %d",c);

    a=5;
    b=10;
    c=15;
    ip = &a;
    printf("\nValue after hardcoding of a = %d",*ip);
    ip = &b;
    printf("\nValue after hardcoding of b = %d",*ip);
    ip=&c;
    printf("\nValue after hardcoding of c = %d",*ip);

    printf("\nEnter the values\n");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    ip = &a;
    printf("\nValue after softcoding of a = %d",*ip);
    ip = &b;
    printf("\nValue after softcoding of b = %d",*ip);
    ip=&c;
    printf("\nValue after softcoding of c = %d",*ip);

    a+=10;
    b+=10;
    c+=10;
    ip = &a;
    printf("\nValue after modifying of a = %d",*ip);
    ip = &b;
    printf("\nValue after modifying of b = %d",*ip);
    ip=&c;
    printf("\nValue after modifying of c = %d",*ip);

    ip=&a;
    printf("\nValue at ip = %d",*ip);
    ip--;
    printf("\nValue of b = %d",*ip);
    ip--;
    printf("\nValue of c = %d",*ip);
}
