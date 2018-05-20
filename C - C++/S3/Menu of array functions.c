#include<stdio.h>
void main()
{
    int i,j,k,n,l,op,pos,num[50],flag=0;
    char c;
    printf("Enter limit for array (max 50)\n");
    scanf("%d",&l);
    i=l;
    printf("Enter elements for array\n");
    for(j=0;j<=l;j++)
        scanf("%d",&num[j]);
    do
    {

        printf("Select option\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Search an element\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
               if(i==l)
               {
                   printf("The array is full\n");
                   printf("The elements in array are\n");
                     for(j=0;j<=i;j++)
                        printf("%d ",num[j]);
                   break;
               }
                printf("Enter position to enter element (between 0 and %d)\n",l);
                scanf("%d",&pos);
                if(pos>l)
               {
                   printf("Position is greater than limit\n");
                   break;
               }
               else if(pos<i)
               {
                   for(j=i+1;j>=pos;j--)
                        num[j]=num[j-1];
                        i++;
               }
               else
                {
                    for(j=i+1;j<=pos;j++)
                        num[j]=0;
                   i=pos;
               }
                printf("Enter an element\n");
                scanf("%d",&num[pos]);
                printf("The elements in array are\n");
                for(j=0;j<=i;j++)
                    printf("%d ",num[j]);
                break;
        case 2:
                printf("Enter an element\n");
                scanf("%d",&n);
                for(j=0;j<=i;j++)
                {
                    if(num[j]==n)
                    {
                        for(k=j;k<i;k++)
                            num[k]=num[k+1];
                        j--;
                        i--;
                    }
                }
                if(i<0)
                    printf("The array is empty\n");
                else
                {
                     printf("The elements in array are\n");
                     for(j=0;j<=i;j++)
                        printf("%d ",num[j]);
                }
                break;
        case 3:
                if(i==0)
                {
                    printf("The array is empty\n");
                    break;
                }
                printf("Enter an element\n");
                scanf("%d",&n);
                for(j=0;j<=i;j++)
                {
                    if(num[j]==n)
                    {
                        flag=1;
                        printf("The element %d is at position %d\n",n,j);
                    }
                }
                if(flag==0)
                printf("element is not in the array ");
                break;
        default:
                printf("Invalid option\n");
                break;
        }
        printf("\nDo you wish to enter again ? (Y/N)\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c=='Y'||c=='y');
}
