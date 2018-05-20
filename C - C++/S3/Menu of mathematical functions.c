#include<stdio.h>
#include<math.h>

void main()
{
    int x,op,i,n,f,j,t;
    float sum,rad;
    char c;
    do
    {
        system("cls");
        t=1;
        sum=0;
        printf("Select an option\n");
        printf("1. sin x\n");
        printf("2. cos x\n");
        printf("3. e^x\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
               printf("Enter value for x in degrees\n");
               scanf("%d",&x);
               rad=x*(3.14/180);
               printf("Enter value for n\n");
               scanf("%d",&n);
               for(i=1;i<=n*2;i=i+2)
               {
                   f=1;
                   for(j=1;j<=i;j++)
                    f=f*j;
                   sum=sum+(t*(pow(rad,i)/f));
                   t=t*-1;
               }
               printf("sin %d = %2.2f",x,sum);
               break;

        case 2:
               printf("Enter value for x in degrees\n");
               scanf("%d",&x);
               rad=x*(3.14/180);
               printf("Enter value for n {>1}\n");
               scanf("%d",&n);
               for(i=0;i<n*2;i=i+2)
               {
                   f=1;
                   for(j=1;j<=i;j++)
                    f=f*j;
                   sum=sum+(t*(pow(rad,i)/f));
                   t=t*-1;
               }
               printf("cos %d = %2.2f",x,sum);
               break;

        case 3:
               printf("Enter value for x\n");
               scanf("%d",&x);
               printf("Enter value for n\n");
               scanf("%d",&n);
               for(i=0;i<=n;i++)
               {
                   f=1;
                   for(j=1;j<=i;j++)
                    f=f*j;
                   sum=sum+((pow(x,i))/f);
               }
               printf("e^%d = %2.2f",x,sum);
               break;

        default:
                printf("Invalid option\n");
                break;
        }

        printf("\nDo you wish to enter again ? (Y/N)\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c=='Y'||c=='y');
}
