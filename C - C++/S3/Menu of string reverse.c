#include<stdio.h>
#include<string.h>
void main()
{
    int i,j,len,op;
    char arr[50],arr2[50],c,temp;
    do
    {
        system("cls");
        printf("Enter string\n");
        fflush(stdin);
        gets(arr);
        printf("Select an option\n");
        printf("1. Reverse a string without using string handling fuction\n");
        printf("2. Reverse a string using string handling fuction\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                for(i=0;arr[i]!='\0';i++);
                len=i-1;
                for(i=0,j=len;i<(len/2);i++,j--)
                {
                    temp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=temp;
                }
                break;
            case 2:
                strrev(arr);
                break;
            default:
                printf("Invalid option\n");
                break;

        }

        printf("The reversed string is\n");
        puts(arr);
        printf("\nDo you wish to enter again ? (Y/N)\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c=='Y'||c=='y');
}


