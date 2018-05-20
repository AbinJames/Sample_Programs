#include<stdio.h>
void main()
{
    struct employee
    {
        char empname[50],department[50];
        float empsal;
        int empid;
    }e[100];
    int op,n,i=0,j,display;
    float salinc;
    char c;
    do
    {
        display=0;
        printf("Selet option\n");
        printf("1. Enter employee information\n");
        printf("2. Increment employee salary\n");
        printf("3. Display employee information\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                if(i==100)
                {
                    printf("The list is full\n");
                    break;
                }
                printf("Enter number of employee you wish to enter\n");
                scanf("%d",&n);
                for(j=0;j<n;j++)
                {
                    printf("\nEnter details of employee %d\n",j+1);
                    printf("Name : ");
                    fflush(stdin);
                    gets(e[i].empname);
                    printf("Employee ID : ");
                    scanf("%d",&e[i].empid);
                    printf("Department : ");
                    fflush(stdin);
                    gets(e[i].department);
                    printf("Salary : ");
                    scanf("%f",&e[i].empsal);
                    i++;
                }
                display=1;
                break;
            case 2:
                if(i<=0)
                    printf("The list is empty\n");
                else
                    {
                        printf("Enter amount of salary to be incremented\n");
                        scanf("%f",&salinc);
                        for(j=0;j<i;j++)
                            e[j].empsal=e[j].empsal+salinc;
                        display=1;
                    }
                break;
            case 3:
                if(i<=0)
                    printf("The list is empty\n");
                else
                    display=1;
                break;
            default:
                printf("Invalid option\n");
                break;
    }
    printf("\n");
    if(display==1)
        {
            for(j=0;j<i;j++)
                {
                        printf("Name        : %s\n",e[j].empname);
                        printf("Employee ID : %d\n",e[j].empid);
                        printf("Department  : %s\n",e[j].department);
                        printf("Salary      : %2.2f\n\n",e[j].empsal);
                }
        }
        printf("\nDo you wish to enter again ? (Y/N)\n");
        fflush(stdin);
        scanf("%c",&c);
}
while(c=='Y'||c=='y');
}
