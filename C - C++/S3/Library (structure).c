#include<stdio.h>
#include<string.h>
void main()
{
    struct Book
    {
        char bookname[50],author[50];
        float price;
        int isdnno;
    }l[100],temp;
    int i=0,j,k,op,op2,n,flag,display,itemp,len;
    float ftemp;
    char c,stemp[50];
    do
    {
        display=0;
        flag=0;
        printf("Select option\n");
        printf("1. Insert book information\n");
        printf("2. Delete a book information\n");
        printf("3. Search a book information\n");
        printf("4. Display book information\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
                if(i==100)
                {
                    printf("The list is full\n");
                    break;
                }
                printf("Enter number of books you wish to enter\n");
                scanf("%d",&n);
                for(j=0;j<n;j++)
                {
                    printf("\nEnter details of book %d\n",j+1);
                    printf("Name : ");
                    fflush(stdin);
                    gets(l[i].bookname);
                    printf("Author : ");
                    fflush(stdin);
                    gets(l[i].author);
                    printf("Price : ");
                    scanf("%f",&l[i].price);
                    printf("ISDN number : ");
                    scanf("%d",&l[i].isdnno);
                    i++;
                }
                display=1;
                break;
        case 2:
                printf("Delete by\n");
                printf("1. Author\n");
                printf("2. ISDN number\n");
                scanf("%d",&op2);
                if(op2==1)
                {
                    fflush(stdin);
                    printf("Enter Author of book\n");
                    gets(stemp);
                }
                else if(op2==2)
                {
                    printf("Enter ISDN number of book\n");
                    scanf("%d",&n);
                }
                for(j=0;j<=i;j++)
                    {
                        if((l[j].isdnno==n&&op2==2)||(strcmp(l[j].author,stemp)==0&&op2==1))
                        {
                            for(k=j;k<i;k++)
                                l[k]=l[k+1];
                            j--;
                            i--;
                        }
                    }
                if(i<0)
                    printf("The list is empty\n");
                else
                    display=1;
                break;
        case 3:
                if(i==0)
                {
                    printf("The list is empty\n");
                    break;
                }
                printf("Search by\n");
                printf("1. Author\n");
                printf("2. ISDN number\n");
                scanf("%d",&op2);
                if(op2==1)
                {
                    fflush(stdin);
                    printf("Enter Author of book\n");
                    gets(stemp);
                }
                else if(op2==2)
                {
                    printf("Enter ISDN number of book\n");
                    scanf("%d",&n);
                }
                for(j=0;j<i;j++)
                {
                    if((l[j].isdnno==n&&op2==2)||(strcmp(l[j].author,stemp)==0&&op2==1))
                    {
                        flag=1;
                        printf("Book Name   : %s\n",l[j].bookname);
                        printf("Author      : %s\n",l[j].author);
                        printf("Price       : %2.2f\n",l[j].price);
                        printf("ISDN number : %d\n\n",l[j].isdnno);
                    }
                }
                if(flag==0)
                printf("\nNO ITEM Found\n");
                break;
        case 4:
            if(i<=0)
                    printf("The list is empty\n");
                else
                    display=1;
            break;
        default:
                printf("Invalid option\n");
                break;
        }
        if(op==1)
        {
            for(j=0;j<i;j++)
            {
                for(k=0;k<i-j-1;k++)
                {
                    if(l[k].isdnno>l[k+1].isdnno)
                    {
                        temp=l[k];
                        l[k]=l[k+1];
                        l[k+1]=temp;
                    }
                }
            }
        }
        printf("\n");
        if(display==1)
        {
            for(j=0;j<i;j++)
                {
                        printf("Book Name   : %s\n",l[j].bookname);
                        printf("Author      : %s\n",l[j].author);
                        printf("Price       : %2.2f\n",l[j].price);
                        printf("ISDN number : %d\n\n",l[j].isdnno);
                }
        }
        printf("\nDo you wish to enter again ? (Y/N)\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c=='Y'||c=='y');

}

