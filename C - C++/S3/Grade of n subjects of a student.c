#include<stdio.h>
void main()
{
    int l,i,a[20];
    float avg,sum;
    char c;
    do
    {
       system("cls");
       printf("Enter number of subjects\n");
       scanf("%d",&l);
       for(i=0,sum=0;i<l;i++)
       {
            printf("Enter marks of subject %d (out of 100)\n",i+1);
            scanf("%d",&a[i]);
            sum=sum+a[i];
       }
       avg=sum/l;
       printf("The average is %2.2f\n",avg);
       if(avg<=100&&avg>90)
            printf("Grade is A");
       else if(avg>80)
            printf("Grade is B");
       else if(avg>70)
            printf("Grade is C");
       else if(avg>60)
            printf("Grade is D");
       else if(avg>=50)
            printf("Grade is E");
       else
            printf("Grade is F");
       printf("\nDo you wish to enter again ? (Y/N)\n");
       fflush(stdin);
       scanf("%c",&c);
    }
    while(c=='Y'||c=='y');
}


