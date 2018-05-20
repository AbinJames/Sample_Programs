#include<stdio.h>
#include<math.h>

void main()
{
    int n,temp,sum=0,n2;
    printf("Enter number\n");
    scanf("%d",&n);
    temp=n;
    while(n!=0)
    {
        n2=n%10;
        sum=sum+pow(n2,3);
        n=n/10;

    }
    if(temp==sum)
        printf("The number is an armstrong number");
    else
        printf("The number is not an armstrong number");
}

