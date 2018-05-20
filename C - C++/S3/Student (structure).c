#include<stdio.h>
struct student
    {
        char name[50];
        int rollno;
    }s[100];
void display(struct student s[100],int n);
void main()
{
    int op,n,i=0,j;
    char c;
    do
    {
        printf("Selet option\n");
        printf("1. Enter student information\n");
        printf("2. Display student information\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                if(i==100)
                {
                    printf("The list is full\n");
                    break;
                }
                printf("Enter number of students you wish to enter\n");
                scanf("%d",&n);
                for(j=0;j<n;j++)
                {
                    printf("\nEnter details of student %d\n",j+1);
                    printf("Name : ");
                    fflush(stdin);
                    gets(s[i].name);
                    printf("Roll no : ");
                    scanf("%d",&s[i].rollno);
                    i++;
                }
                display(s,i);
                break;
            case 2:
                if(i<=0)
                    printf("The list is empty\n");
                else
                    display(s,i);
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
void display(struct student s[100],int n)
{
    int j;
    printf("\n");
    for(j=0;j<n;j++)
                {
                        printf("Name    : %s\n",s[j].name);
                        printf("Roll no : %d\n",s[j].rollno);
                }
}
