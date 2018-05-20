#include<stdio.h>

void print(int a[])
{
    int i;
    for(i=0;i<10;i++)
        printf("%5d",a[i]);
    printf("\n");
}

void quicksort(int arr[],int left,int right)
{
    int pivot=arr[left],l=left,r=right,temp,i;
    printf("pivot = %d\n",pivot);
    while(l<r)
    {
        while(arr[r]>pivot)
            r--;
        temp=arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
        printf("The array is\n");
        for(i=0;i<left;i++)
            printf("     ");
        for(i=left;i<=right;i++)
            printf("%5d",arr[i]);
        for(i=right;i<10;i++)
            printf("     ");
    printf("\n");
        while(arr[l]<pivot)
            l++;
            printf("right = %d r = %d left = %d l = %d\n",right,r,left,l);
        if(right-r>1)
        {
            printf("Going into right\n");
            quicksort(arr,l+1,right);
        }

        if(l-left>1)
        {
            printf("Going into left\n");
            quicksort(arr,left,r-1);
        }

        printf("While end\n");
    }

}

void main()
{
    int a[10]={5,7,6,4,10,9,1,2,3,8},l=0,r=9;
    printf("The array is\n");
    print(a);
    quicksort(a,l,r);
    printf("The sorted array is\n");
    print(a);
}
