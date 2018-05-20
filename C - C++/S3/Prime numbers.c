#include<stdio.h>

void main()
{
    int n,i,j,prime;
    printf("Enter the limit of numbers\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        prime=0;
        for(j=2;j<=(i/2);j++)
        {
            if(i%j==0)
            {
                prime=1;
                break;
            }
        }
        if(prime==0)
        printf("%d ",i);
    }
}
