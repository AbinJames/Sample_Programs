#include<stdio.h>
#include<string.h>
#define SIZE 100
void stringchange(char[]);
void main()
{
    char c,a[SIZE];
    do
    {
        printf("Enter string\n");
        fflush(stdin);
        gets(a);
        stringchange(a);
        printf("Do you wish to enter again?(y/n)\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c=='Y'||c=='y');
}

void stringchange(char arr[])
{
    int i,n;
    for(i=0;arr[i]!='\0';i++)
    {
        n=arr[i];
        if(n>=97&&n<=122)
                arr[i]=n-32;
        else if(n>=65&&n<=90)
                arr[i]=n+32;

    }
    printf("The converted string is\n");
    puts(arr);
}


