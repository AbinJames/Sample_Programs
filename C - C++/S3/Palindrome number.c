#include<stdio.h>

void main()
{
    int n,temp,temp2,sum=0;
    printf("Enter number\n");
    scanf("%d",&n);
    temp2=n;
    while(n!=0)
    {
        sum=sum*10;
        temp=n%10;
        sum=sum+temp;
        n=n/10;

    }
    printf("The reversed number is %d\n",sum);
    if(temp2==sum)
        printf("The number is  palindrome");
    else
        printf("The number is not palindrome");
}
