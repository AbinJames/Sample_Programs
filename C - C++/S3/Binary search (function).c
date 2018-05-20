#include<stdio.h>
void binarysearch(int,int,int[]);
void main()
{
    int b[100],m,p,i;
    char c;
    do
    {
        system("cls");
        printf("Enter number of elements\n");
        scanf("%d",&m);
        printf("Enter elements in ascending order\n");
        for(i=0;i<m;i++)
            scanf("%d",&b[i]);
        printf("Enter element to search for\n");
        scanf("%d",&p);
        binarysearch(m,p,b);
        printf("Do you wish to enter again ? (y/n)\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c=='Y'||c=='y');
}

void binarysearch(int l,int n,int a[100])
{
    int up,low=0,mid,i,flag=0;
    up=l-1;
    while(low<=up)
        {
            mid=(low+up)/2;
            if(a[mid]<n)
                low=mid+1;
            else if(a[mid]>n)
                up=mid;
            else
            {
                printf("The number is at position %d\n",mid);
                flag=1;
                break;
            }

        }
        if(flag==0)
            printf("The element is not found\n");
}
