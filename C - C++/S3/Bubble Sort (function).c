#include<stdio.h>
void bubblesort(int,int[]);
void main()
{
    int b[100],m,i;
    char c;
    do
    {
        system("cls");
        printf("Enter number of elements\n");
        scanf("%d",&m);
        printf("Enter elements\n");
        for(i=0;i<m;i++)
            scanf("%d",&b[i]);
        bubblesort(m,b);
        printf("Do you wish to enter again ? (y/n)\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c=='Y'||c=='y');
}

void bubblesort(int l,int a[100])
{
    int i,j,temp;
    for(i=0;i<l;i++)
    {
        for(j=0;j<l-i-1;j++)
        {
          if(a[j]>a[j+1])
          {
              temp=a[j+1];
              a[j+1]=a[j];
              a[j]=temp;
          }
        }
    }
    printf("The sorted array is\n");
        for(i=0;i<l;i++)
            printf("%d\t",a[i]);
}
