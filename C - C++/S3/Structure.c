#include<stdio.h>


void main()
{
    struct student
    {
        int num;
        char name[20],batch;
        float mark;
    };
    struct student a,b,*stptr;
    printf("Address of a");
    printf("\na = %u\nnum = %u\nname = %u\nbatch = %u\nmark = %u",&a,&a.num,&a.name,&a.batch,&a.mark);

    printf("\n\nAddress of b");
    printf("\nb = %u\nnum = %u\nname = %u\nbatch = %u\nmark = %u",&b,&b.num,&b.name,&b.batch,&b.mark);

    printf("\n\nAddress of stptr = %u",&stptr);
    stptr=&b;
    printf("\n\nInitial values of a");
    printf("\nnum = %d",a.num);
    printf("\nname = %s",a.name);
    printf("\nbatch = %c",a.batch);
    printf("\nmark = %f",a.mark);


    printf("\n\nInitial values of b");
    printf("\nnum = %d",stptr->num);
    printf("\nname = %s",stptr->name);
    printf("\nbatch = %c",stptr->batch);
    printf("\nmark = %f",stptr->mark);

    a.num = 10;
    strcpy(a.name,"Abin");
    a.batch = 'A';
    a.mark = 2.01;

    printf("\n\nValues of a after hardcoding");
    printf("\nnum = %d",a.num);
    printf("\nname = %s",a.name);
    printf("\nbatch = %c",a.batch);
    printf("\nmark = %f",a.mark);

    stptr->num = 20;
    strcpy(stptr->name,"Anand");
    stptr->batch = 'B';
    stptr->mark = 5.02;

    printf("\n\nValues of b after hardcoding");
    printf("\nnum = %d",stptr->num);
    printf("\nname = %s",stptr->name);
    printf("\nbatch = %c",stptr->batch);
    printf("\nmark = %f",stptr->mark);

    printf("\n\nEnter values of a structure\n");
    scanf("%d",&a.num);
    fflush(stdin);
    gets(a.name);
    fflush(stdin);
    scanf("%c",&a.batch);
    scanf("%f",&a.mark);

    printf("\n\nValues of a after softcoding");
    printf("\nnum = %d",a.num);
    printf("\nname = %s",a.name);
    printf("\nbatch = %c",a.batch);
    printf("\nmark = %f",a.mark);

    printf("\n\nEnter values of b structure\n");
    scanf("%d",&stptr->num);
    fflush(stdin);
    scanf("%s",&stptr->name);
    fflush(stdin);
    scanf("%c",&stptr->batch);
    scanf("%f",&stptr->mark);

    printf("\n\nValues of b after softcoding");
    printf("\nnum = %d",stptr->num);
    printf("\nname = %s",stptr->name);
    printf("\nbatch = %c",stptr->batch);
    printf("\nmark = %f",stptr->mark);

    a.num++;
    strrev(a.name);
    a.batch='C';
    a.mark+=1.5;

    printf("\n\nValues of a after modifying");
    printf("\nnum = %d",a.num);
    printf("\nname = %s",a.name);
    printf("\nbatch = %c",a.batch);
    printf("\nmark = %f",a.mark);

    stptr->num++;
    strrev(stptr->name);
    stptr->batch='D';
    stptr->mark+=1.5;

    printf("\n\nValues of b after softcoding");
    printf("\nnum = %d",stptr->num);
    printf("\nname = %s",stptr->name);
    printf("\nbatch = %c",stptr->batch);
    printf("\nmark = %f",stptr->mark);
}
