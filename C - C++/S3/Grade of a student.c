#include<stdio.h>
void main()
{
    int s1,s2,s3,s4,s5,s6,avg;
    printf("Enter marks of student in subject 1\n");
    scanf("%d",&s1);
    printf("Enter marks of student in subject 2\n");
    scanf("%d",&s2);
    printf("Enter marks of student in subject 3\n");
    scanf("%d",&s3);
    printf("Enter marks of student in subject 4\n");
    scanf("%d",&s4);
    printf("Enter marks of student in subject 5\n");
    scanf("%d",&s5);
    printf("Enter marks of student in subject 6\n");
    scanf("%d",&s6);
    avg=(s1+s2+s3+s4+s5+s6)/6;
    if(avg<=100&&avg>90)
        printf("Grade is A");
    else if(avg<=90&&avg>80)
        printf("Grade is B");
    else if(avg<=80&&avg>70)
        printf("Grade is C");
    else if(avg<=70&&avg>60)
        printf("Grade is D");
    else if(avg<=60&&avg>50)
        printf("Grade is E");
    else
        printf("Grade is F");
}
