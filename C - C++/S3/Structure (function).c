#include<stdio.h>
#include<string.h>

struct student
{
    char name[80];
    int rollno,marks;
}s[10];

void print(struct student s);

void main()
{
    strcpy(s[1].name,"Abin Anil");
    s[1].rollno=1;
    s[1].marks=50;
    strcpy(s[2].name,"Abin James");
    s[2].rollno=2;
    s[2].marks=50;
    print(s[1]);
    print(s[2]);
}

void  print(struct student s)
{
    printf("Name    : %s\n",s.name);
    printf("Roll no : %d\n",s.rollno);
    printf("Marks   : %d\n\n",s.marks);
}
