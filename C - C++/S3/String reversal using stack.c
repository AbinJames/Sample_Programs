#include<stdio.h>
#include<stdlib.h>
struct node
{
    char ch;
    struct node * link;
};

void traverse(struct node * nptr)
{
    printf("The string is now \n");
    while(nptr!=NULL)
    {

        printf("%c",nptr->ch);
        nptr=nptr->link;
    }
}

struct node * push(struct node **top, char string[])
{
    int i;
    struct node * nodeptr;
    for(i=0;string[i]!='\0';i++)
    {
        nodeptr=(struct node *)malloc(sizeof(struct node));
        if(nodeptr==NULL)
            printf("Memory Full\n");
        else
        {
            nodeptr->ch=string[i];
            nodeptr->link= *top;
            *top=nodeptr;
        }
    }

}

void main()
{
    struct node * top=NULL;
    char string[20];
    printf("Enter string\n");
    gets(string);
    push(&top,string);
    traverse(top);
}

