#include<stdio.h>

void main()
{
    int a,b,op;
    printf("Enter two numbers\n");
    scanf("%d %d",&a,&b);
    printf("Select the desired arithmetic operation\n");
    printf("1. Add (+)\n");
    printf("2. Subtract (-)\n");
    printf("3. Multiply (*)\n");
    printf("4. Divide and show quotient (/)\n");
    printf("5. Divide and show remainder (/)\n");
    printf("6. Exit\n");
    scanf("%d",&op);
    if(op==1)
        printf("%d + %d = %d\n",a,b,a+b);
    else if(op==2)
        printf("%d - %d = %d\n",a,b,a-b);
    else if(op==3)
        printf("%d * %d = %d\n",a,b,a*b);
    else if(op==4)
        printf("%d / %d = %d\n",a,b,a/b);
    else if(op==5)
        printf("%d / %d = %d\n",a,b,a%b);
    else if(op==6);
    else
        printf("Invalid option\n");

}
