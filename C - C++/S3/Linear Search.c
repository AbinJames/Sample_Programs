#include<stdio.h>
void display(int a[10])
{
    int pos;
    for(pos=0;pos<10;pos++)
            printf("%5d",a[pos]);
}
void linearsearch(int s,int e,int a[])
{
    int pos,flag=0;
    for(pos=0;pos<s;pos++)
    {
        if(a[pos]==e)
        {
            printf("\nThe element is at position %d (position starting from 0)\n",pos+1);
            flag=1;
        }
    }
    if(flag==0)
        printf("\nThe element is not found\n");
}
void linearsearchp(int s,int e,int *a)
{
    int pos,flag=0;
    for(pos=0;pos<s;pos++)
    {
        if(*(a+pos)==e)
        {
            printf("\nThe element is at position %d (position starting from 0)\n",pos);
            flag=1;
        }
    }
    if(flag==0)
        printf("\nThe element is not found\n");
}
void main()
{
    int size=10,ele=0,arr1[10]={10,5,42,8,9,5,55,100,1,2};
    printf("linear search without pointer\n");
    printf("The elements are\n");
    display(arr1);
    printf("\nEnter element to search for : ");
    scanf("%d",&ele);
    linearsearch(size,ele,arr1);
    int arr2[10]={9,8,1,2,3,6,7,10,15,20};
    printf("linear search with pointer\n");
    printf("The elements are\n");
    display(arr2);
    printf("\nEnter element to search for : ");
    scanf("%d",&ele);
    linearsearchp(size,ele,arr2);
}

