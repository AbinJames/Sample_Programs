#include<stdio.h>
void main()
{
    int i,n,temp=1,sum=0,temp2;
    printf("Enter limit for numbers in fionacci series\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("%d ",sum);
        temp2=sum+temp;
        sum=temp;
        temp=temp2;
    }
}
