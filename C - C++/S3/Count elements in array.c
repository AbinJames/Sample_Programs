#include<stdio.h>
void main()
{
    int l,i,a[20],count,n;
    char c;
    do
    {
       system("cls");
       printf("Enter number of elements\n");
       scanf("%d",&l);
       count=0;
       printf("Enter elements\n");
       for(i=0;i<l;i++)
            scanf("%d",&a[i]);
       printf("Enter element to search for\n");
       scanf("%d",&n);
       for(i=0;i<l;i++)
       {
            if(a[i]==n)
                count++;
       }
       printf("The element %d is present %d times",n,count);
       printf("\nDo you wish to enter again ? (Y/N)\n");
       fflush(stdin);
       scanf("%c",&c);
    }
    while(c=='Y'||c=='y');
}


