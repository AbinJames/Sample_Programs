#include<stdio.h>
void display(int a[10])
{
    int pos;
    for(pos=0;pos<10;pos++)
            printf("%5d",a[pos]);
}
void selectionsort(int a[10])
{
    int pos,pass,temp;
    for(pass=1;pass<10;pass++)
    {
        pos=pass;
	temp=a[pos];
         while(a[pos]<a[pos-1]&&pos>0)
        {
            a[pos]=a[pos-1];
            pos--;
        }
	a[pos-1]=temp;
        printf("\nAFTER PASS %d\n",pass);
        display(a);
    }

}
void selectionsortp(int *a)
{
   int pos,pass,temp;
    for(pass=1;pass<10;pass++)
    {
        pos=pass;
         while(*(a+pos)<*(a+pos-1)&&pos>0)
        {
            temp=*(a+pos);
            *(a+pos)=*(a+pos-1);
            a[pos-1]=temp;
            pos--;
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
