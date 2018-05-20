#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num;
    struct node * link;
};

void traverse(struct node * nptr)
{

    printf("The list is now \n");
    while(nptr!=NULL)
    {

        printf("%5d",nptr->num);
        nptr=nptr->link;
    }
}

void insertfront(struct node ** start)
{
    struct node * nodeptr;
    nodeptr=(struct node *)malloc(sizeof(struct node));
    if(nodeptr==NULL)
    {
        printf("Memory Full\n");
        return;
    }
    printf("Enter number\n");
    scanf("%d",&nodeptr->num);
    nodeptr->link=*start;
    *start=nodeptr;
}

void insertbtwa(struct node * pos,struct node ** end)
{
    int n;
    printf("Enter number after which you want to insert\n");
    scanf("%d",&n);
    while(pos!=NULL && pos->num!=n)
        pos=pos->link;
    if(pos==NULL)
    {
        printf("No such number\n");
        return;
    }
    struct node * nodeptr;
    nodeptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter number\n");
    scanf("%d",&nodeptr->num);
    nodeptr->link=NULL;
    if(pos->link==NULL)
    {
        (*end)->link=nodeptr;
        *end=nodeptr;
    }
    else
    {
        nodeptr->link=pos->link;
        pos->link=nodeptr;
    }

}

void insertbtwb(struct node ** start)
{
    int n;
    struct node * pos = *start;
    if(pos==NULL)
    {
        printf("There are no nodes to select\n");
        return;
    }
    printf("Enter number before which you want to insert\n");
    scanf("%d",&n);
    if(pos->num!=n)
    {
        while(pos->link!=NULL && (pos->link)->num!=n)
            pos=pos->link;
        if(pos->link==NULL)
            printf("No such number\n");
        else
        {
            struct node * nodeptr;
            nodeptr=(struct node *)malloc(sizeof(struct node));
            printf("Enter number\n");
            scanf("%d",&nodeptr->num);
            nodeptr->link=pos->link;
            pos->link=nodeptr;
        }
    }
    else
    {
        struct node * nodeptr;
        nodeptr=(struct node *)malloc(sizeof(struct node));
        printf("Enter number\n");
        scanf("%d",&nodeptr->num);
        nodeptr->link=*start;
        *start=nodeptr;
    }
}

void insertend(struct node ** end)
{
    struct node * nodeptr;
    nodeptr=(struct node *)malloc(sizeof(struct node));
    if(nodeptr==NULL)
    {
        printf("Memory Full\n");
    }
    else
    {
        printf("Enter number\n");
        scanf("%d",&nodeptr->num);
        nodeptr->link=NULL;
        if(*end==NULL)
            *end=nodeptr;
        else
        {
            (*end)->link=nodeptr;
            *end=nodeptr;
        }

    }
}

int isempty(struct node * start)
{
    if(start==NULL)
        return(1);
    return(0);
}

int delfront(struct node ** start)
{
    int n;
    struct node * temp;
    n = (*start)->num;
    temp=*start;
    (*start)=(*start)->link;
    free(temp);
    return(n);
}

int delbtwa(struct node * pos,struct node ** end)
{
    int n;
    struct node * temp;
    if(pos->link == NULL)
        printf("No more nodes after current node\n");
    else
    {
        printf("Enter number after which you want to delete\n");
        scanf("%d",&n);
        while(pos->link!=NULL && pos->num!=n)
            pos=pos->link;
        if(pos->link==NULL && pos->num!=n)
            printf("No such number\n");
        else if(pos->link==NULL)
            printf("No more nodes after current node\n");
        else
        {
            n=(pos->link)->num;
            temp=pos->link;
            pos->link=(pos->link)->link;
            if(pos->link==NULL)
                *end = pos;
            free(temp);
            return (n);
        }
    }
}

int delbtwb(struct node ** start)
{
    int n,a;
    struct node * pos,*temp;
    pos=(*start);
    if(pos->link == NULL)
        printf("No more nodes before current node\n");
    else if((pos->link)->link == NULL || (pos->link)->num == n)
    {
        printf("Enter number before which you want to delete\n");
        scanf("%d",&n);
        if((pos->link)->num == n)
        {
            a = (*start)->num;
            (*start) = (*start)->link;
            temp=*start;
            free(temp);
            return(a);
        }
        else
            printf("No node before current node\n");

    }
    else
    {
        printf("Enter number before which you want to delete\n");
        scanf("%d",&n);
        while((pos->link)->link!=NULL && ((pos->link)->link)->num!=n)
            pos=pos->link;
        if((pos->link)->link == NULL)
            printf("No such number\n");
        else
        {
            a = (pos->link)->num;
            temp=pos->link;
            pos->link=(pos->link)->link;
            free(temp);
            return (a);
        }

    }
}

int delend(struct node ** end,struct node * pos)
{
    int n;
    struct node* temp;
    if(pos->link==NULL)
    {
        n = pos -> num;
        *end=NULL;
        free(pos);
        return (n);
    }

    else
    {
        while((pos->link)->link!=NULL)
            pos=pos->link;
        n = (pos->link)->num;
        temp=pos->link;
        pos->link=NULL;
        *end=pos;
        free(temp);
        return(n);
    }
}

void main()
{
    struct node *start=NULL,*end=NULL;
    int op=1,ele;
    while(op!=0)
    {
        printf("\nEnter option\n");
        printf("1. Insert node at start\n");
        printf("2. Insert node in between (after)\n");
        printf("3. Insert node in between (before)\n");
        printf("4. Insert node at end\n");
        printf("5. Delete node at start\n");
        printf("6. Delete node in between (after)\n");
        printf("7. Delete node in between (before)\n");
        printf("8. Delete node at end\n");
        printf("9. Display list\n");
        printf("0. Exit\n");
        scanf("%d",&op);

        switch(op)
        {
        case 1:
            insertfront(&start);
            if(end==NULL)
                end=start;
            traverse(start);
            break;
        case 2:
            insertbtwa(start,&end);
            traverse(start);
            break;
        case 3:
            insertbtwb(&start);
            traverse(start);
            break;
        case 4:
            insertend(&end);
            if (start==NULL)
                start = end;
            traverse(start);
            break;
        case 5:
            if(!isempty(start))
            {
                ele=delfront(&start);
                printf("Deleted element : %d\n",ele);
            }
            else
                printf("The list is empty\n");
            traverse(start);
            break;
        case 6:
            if(!isempty(start))
            {
                ele=delbtwa(start,&end);
                printf("Deleted element : %d\n",ele);
            }
            else
                printf("The list is empty\n");
            traverse(start);
            break;
        case 7:
            if(!isempty(start))
            {
                ele = delbtwb(&start);
                printf("Deleted element : %d\n",ele);
            }
            else
                printf("The list is empty\n");
            traverse(start);
            break;
        case 8:
            if(!isempty(start))
            {
                ele = delend(&end,start);
                printf("Deleted element : %d\n",ele);
                if(end==NULL)
                    start = NULL;
            }
            else
                printf("The list is empty\n");
            traverse(start);
            break;
        case 9:
            traverse(start);
            break;
        case 0:
            break;
        default:
            printf("Invalid option\n");
            break;

        }
    }
}
