#include<stdio.h>
void display(int a[10])
{
    int pos;
    for(pos=0;pos<10;pos++)
            printf("%5d",a[pos]);
}
void binarysearch(int s,int e,int a[])
{
    int up,low=0,mid,flag=0;
    up=s-2;
    while(low<=up)
    {
        mid=(up+low)/2;
        if(a[mid]<e)
            low=mid+1;
        else if(a[mid]>e)
            up=mid-1;
        else
        {
            printf("\nThe element is at position %d\n",mid+1);
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("\nThe element is not found\n");
}
void binarysearchp(int s,int e,int *a)
{
    int up,low=0,mid,flag=0;
    up=s-1;
    while(low<=up)
    {
        mid=(up+low)/2;
        if(*(a+mid)<e)
            low=mid+1;
        else if(*(a+mid)>e)
            up=mid-1;
        else
        {
            printf("\nThe element is at position %d \n",mid+1);
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("\nThe element is not found\n");
}
void main()
{
    int size=10,ele,arr1[10]={5,10,15,20,25,30,35,40,45,50};
    printf("Binary search without pointer\n");
    printf("The elements are\n");
    display(arr1);
    printf("\nEnter element to search for : ");
    scanf("%d",&ele);
    binarysearch(size,ele,arr1);

    printf("Binary search with pointer\n");
    int arr2[10]={1,2,3,4,5,6,7,8,9,10};
    printf("The elements are\n");
    display(arr2);
    printf("\nEnter element to search for : ");
    scanf("%d",&ele);
    binarysearchp(size,ele,arr2);
}

