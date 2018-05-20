#include<stdio.h>
void display(int a[10])
{
    int pos;
    for(pos=0;pos<10;pos++)
            printf("%5d",a[pos]);
}
void bubblesort(int a[10])
{
   int n=10,pos,pass,temp;
   for(pass=0;pass<n-1;pass++)
    {
        for(pos=0;pos<n-pass-1;pos++)
        {
            if(a[pos]>a[pos+1])
            {
                temp=a[pos];
                a[pos]=a[pos+1];
                a[pos+1]=temp;
            }
        }
        printf("\nAFTER PASS %d\n",pass);
        display(a);
    }
}
void bubblesortp(int *a)
{
   int n=10,pos,pass,temp;
   for(pass=0;pass<=n-1;pass++)
    {
        for(pos=0;pos<n-pass-1;pos++)
        {
            if(*(a+pos)>*(a+pos+1))
            {
                temp=*(a+pos);
                *(a+pos)=*(a+pos+1);
                *(a+pos+1)=temp;
            }
        }
        printf("\nAFTER PASS %d\n",pass);
        display(a);
    }
}
void main()
{
    int arr1[10]={10,8,1,2,4,9,7,6,3,5},pos;
    printf("Sorting without pointer\n");
    printf("The elements are\n");
    display(arr1);
    bubblesort(arr1);
    printf("\nAfter complete sort\n");
    display(arr1);

    int arr2[10]={9,1,7,10,5,4,8,6,2,3};
    printf("\n\nSorting with pointer\n");
    printf("The elements are\n");
    display(arr2);
    bubblesortp(arr2);
    printf("\nAfter complete sort\n");
    display(arr2);
}
