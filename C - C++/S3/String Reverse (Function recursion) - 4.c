#include<stdio.h>
#define SIZE 100
void stringchange(char arr[],int l,int j);
void main()
{
    char c,a[SIZE];
    int i;
    do
    {
            printf("Enter the string\n");
            fflush(stdin);
            gets(a);
            for(i=1;a[i]!='\0';i++);
            printf("The reversed string is \n");
            stringchange(a,i-1,0);
            printf("\nDo you wish to enter again ? (y/n)\n");
            fflush(stdin);
            scanf("%c",&c);
    }
    while(c=='Y'||c=='y');
}

void stringchange(char arr[],int l,int j)
{
    char temp;
    if(j<=l)
    {
        temp=arr[j];
        arr[j]=arr[l];
        arr[l]=temp;
        stringchange(arr,l-1,j+1);
    }
    else
        puts(arr);
}

