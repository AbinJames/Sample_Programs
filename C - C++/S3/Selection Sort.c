#include<stdio.h>
void display(int a[10])
{
    int pos;
    for(pos=0;pos<10;pos++)
            printf("%5d",a[pos]);
}
void selectionsort(int a[10])
{
   int n=10,pos,pass,small,sp,temp;
   for(pass=0;pass<n;pass++)
    {
        small=a[pass];
        sp=pass;
        for(pos=pass+1;pos<n;pos++)
        {
            if(small>a[pos])
            {
                small=a[pos];
                sp=pos;
            }
        }
        if(sp!=pass)
        {
            temp=a[sp];
            a[sp]=a[pass];
            a[pass]=temp;
        }
        printf("\nAFTER PASS %d\n",1);
        display(a);
    }
}
void selectionsortp(int *a)
{
   int n=10,pos,pass,small,sp,temp;
   for(pass=0;pass<n;pass++)
    {
        small=*(a+pass);
        sp=pass;
        for(pos=pass+1;pos<n;pos++)
        {
            if(small>a[pos])
            {
                small=*(a+pos);
                sp=pos;
            }
        }
        if(sp!=pass)
        {
            temp=*(a+sp);
            *(a+sp)=*(a+pass);
            *(a+pass)=temp;
        }

        printf("\nAFTER PASS %d\n",1);
        display(a);
    }
}
void main()
{
    int arr1[10]={10,8,1,2,4,9,7,6,3,5},pos;
    printf("Sorting without pointer\n");
    printf("The elements are\n");
    display(arr1);
    selectionsort(arr1);
    printf("\nAfter complete sort\n");
    display(arr1);

    int arr2[10]={9,1,7,10,5,4,8,6,2,3};
    printf("\n\nSorting with pointer\n");
    printf("The elements are\n");
    display(arr2);
    selectionsortp(arr2);
    printf("\nAfter complete sort\n");
    display(arr2);
}
