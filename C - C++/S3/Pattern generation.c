#include<stdio.h>

void main()
{
    int n,i,j;
    printf("Enter the limit\n");
    scanf("%d",&n);
    for(i=n;i>=1;i--)
    {
        for(j=n;j>=i;j--)
        if(i<10)
            printf("%d  ",i);
        else
            printf("%d ",i);
        printf("\n");
    }
}
