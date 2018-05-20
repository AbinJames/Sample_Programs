#include<stdio.h>
void main()
{
    int l,i=0,a[20],b[20];
    char c;
    do
    {
        system("cls");
       printf("Enter limit of array (max 20) \n");
       scanf("%d",&l);
       printf("Enter elments of array\n");
       for(i=0;i<l;i++)
       {
            scanf("%d",&a[i]);
            b[i]=a[i];
       }
       printf("The elements of array is \n");
       for(i=0;i<l;i++)
            printf("%d ",a[i]);
       printf("\nCopy of array is \n");
       for(i=0;i<l;i++)
            printf("%d ",b[i]);
       printf("\nDo you wish to enter again ? (Y/N)\n");
       fflush(stdin);
       scanf("%c",&c);
    }
    while(c=='Y'||c=='y');
}

