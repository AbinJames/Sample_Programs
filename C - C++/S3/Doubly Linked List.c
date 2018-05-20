#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num;
    struct node * flink,* blink;
};

void traverseforward(struct node * start)
{
    printf("TRAVERSING FORWARD\n");
    while(start!=NULL)
    {
        printf("%5d",start->num);
        start=start->flink;
    }
    printf("\n");
}

void traversereverse(struct node * end)
{
    printf("TRAVERSING REVERSE\n");
    while(end!=NULL)
    {
        printf("%5d",end->num);
        end=end->blink;
    }
    printf("\n");
}
void addatstart(struct node ** start,struct node ** end)
{
    struct node * nodeptr;
    nodeptr=(struct node *)malloc(sizeof(struct node));
    if(nodeptr==NULL)
    {
        printf("Memory is full\n");
        return;
    }
    printf("Enter number\n");
    scanf("%d",&nodeptr->num);
    nodeptr->flink=NULL;
    nodeptr->blink=NULL;
    if(*start==NULL)
    {
        *start=nodeptr;
        *end=nodeptr;
    }
    else
    {
        (*start)->blink=nodeptr;
        nodeptr->flink=*start;
        *start=nodeptr;
    }
}

void addatend(struct node ** start,struct node ** end)
{
    struct node * nodeptr;
    nodeptr=(struct node *)malloc(sizeof(struct node));
    if(nodeptr==NULL)
    {
        printf("Memory is full\n");
        return;
    }
    printf("Enter number\n");
    scanf("%d",&nodeptr->num);
    nodeptr->flink=NULL;
    nodeptr->blink=NULL;
    if(*start==NULL)
    {
        *start=nodeptr;
        *end=nodeptr;
    }
    else
    {
        (*end)->flink=nodeptr;
        nodeptr->blink=*end;
        *end=nodeptr;
    }
}

void inserta(struct node * pos,struct node ** end)
{
    int n;
    if(pos == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Enter number after which you want to insert\n");
    scanf("%d",&n);
    while(pos!=NULL && pos->num!=n)
        pos=pos->flink;
    if(pos==NULL)
    {
        printf("No such number\n");
        return;
    }
    struct node * nodeptr;
    nodeptr=(struct node *)malloc(sizeof(struct node));
    if(nodeptr==NULL)
    {
        printf("Memory is full\n");
        return;
    }
    printf("Enter number\n");
    scanf("%d",&nodeptr->num);
    nodeptr->flink=NULL;
    nodeptr->blink=NULL;
    if(pos->flink==NULL)
    {
        (*end)->flink=nodeptr;
        nodeptr->blink=*end;
        *end=nodeptr;
    }
    else
    {
        nodeptr->blink=pos;
        nodeptr->flink=pos->flink;
        (pos->flink)->blink=nodeptr;
        pos->flink=nodeptr;
    }
}

void insertb(struct node ** start)
{
    int n;
    struct node *pos;
    pos = *start;
    if(pos == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Enter number before which you want to insert\n");
    scanf("%d",&n);
    while(pos!=NULL && pos->num!=n)
        pos=pos->flink;
    if(pos==NULL)
    {
        printf("No such number\n");
        return;
    }
    struct node * nodeptr;
    nodeptr=(struct node *)malloc(sizeof(struct node));
    if(nodeptr==NULL)
    {
        printf("Memory is full\n");
        return;
    }
    printf("Enter number\n");
    scanf("%d",&nodeptr->num);
    nodeptr->flink=NULL;
    nodeptr->blink=NULL;
    if(pos->blink==NULL)
    {
        (*start)->blink=nodeptr;
        nodeptr->flink=*start;
        *start=nodeptr;
    }
    else
    {
        nodeptr->flink=pos;
        nodeptr->blink=pos->blink;
        (pos->blink)->flink=nodeptr;
        pos->blink=nodeptr;
    }
}

int isempty(struct node * start)
{
    if(start==NULL)
        return(1);
    return(0);
}

int delstart(struct node ** start)
{
    int n;
    struct node * nd;
    nd = *start;
    n = (*start)->num;
    *start = (*start)->flink;
    (*start)->blink=NULL;
    free(nd);
    return(n);
}

int delbtwa(struct node * pos,struct node ** end)
{
    int n;
    struct node * nd;
    if(pos->flink == NULL)
    {
        printf("No more nodes after current node\n");
        return(-999);
    }
    printf("Enter number after which you want to delete\n");
    scanf("%d",&n);
    while(pos!=NULL && pos->num!=n)
        pos=pos->flink;
    if(pos==NULL)
    {
        printf("No such number\n");
        return (-999);
    }
    else if(pos->flink==NULL)
    {
        printf("No node after current node\n");
        return(-999);
    }
    else if((pos->flink)->flink==NULL)
    {
        n=(pos->flink)->num;
        nd = pos->flink;
        pos->flink=(pos->flink)->flink;
        *end = pos;
        free(nd);
        return (n);
    }
    else
    {
        n=(pos->flink)->num;
        nd = pos->flink;
        pos->flink=(pos->flink)->flink;
        (pos->flink)->blink = pos;
        free(nd);
        return (n);
    }
}

int delbtwb(struct node ** start)
{
    int n,a;
    struct node * pos,*nd;
    pos=(*start);
    if(pos->flink == NULL)
    {
        printf("No more nodes before current node\n");
        return(-999);
    }
    printf("Enter number before which you want to delete\n");
    scanf("%d",&n);
    while(pos != NULL && pos->num!=n)
        pos=pos->flink;
    if(pos == NULL)
    {
        printf("No such number\n");
        return(-999);
    }
    else if(pos->blink == NULL)
    {
        printf("No more nodes before current node\n");
        return(-999);
    }
    else if((pos->blink)->blink==NULL)
    {
        a = (pos->blink)->num;
        nd = pos -> blink;
        pos->blink=NULL;
        *start=pos;
        free(nd);
        return(a);
    }
    else
    {
        a = (pos->blink)->num;
        nd = pos->blink;
        pos->blink=(pos->blink)->blink;
        (pos->blink)->flink=pos;
        free(nd);
        return (a);
    }
}

int delend(struct node ** start,struct node ** end)
{
    int n;
    struct node * nd;
    if((*start)->flink==NULL)
    {
        n = (*start)->num;
        nd = * start;
        *start=NULL;
        *end=NULL;
    }
    else
    {
        nd = *end;
        n = (*end)->num;
        *end=(*end)->blink;
        (*end)->flink=NULL;
    }
    free(nd);
    return(n);
}

void main()
{
    struct node *start=NULL,*end=NULL;
    int op = 1,elem;
    while(op!=0)
    {
        printf("Enter option\n");
        printf("1. Insert node at start\n");
        printf("2. Insert node in between (after)\n");
        printf("3. Insert node in between (before)\n");
        printf("4. Insert node at end\n");
        printf("5. Delete node at start\n");
        printf("6. Delete node in between (after)\n");
        printf("7. Delete node in between (before)\n");
        printf("8. Delete node at end\n");
        printf("0. Exit\n");
        scanf("%d",&op);

        switch(op)
        {
        case 1:
            addatstart(&start,&end);
            printf("The list is now \n");
            traverseforward(start);
            traversereverse(end);
            break;
        case 2:
            inserta(start,&end);
            printf("The list is now \n");
            traverseforward(start);
            traversereverse(end);
            break;
        case 3:
            insertb(&start);
            printf("The list is now \n");
            traverseforward(start);
            traversereverse(end);
            break;
        case 4:
            addatend(&start,&end);
            printf("The list is now \n");
            traverseforward(start);
            traversereverse(end);
            break;
        case 5:
            if(!isempty(start))
            {
                elem=delstart(&start);
                printf("Deleted element : %d\n",elem);
                printf("The list is now \n");
                traverseforward(start);
                traversereverse(end);
            }
            else
                printf("The list is empty\n");

            break;
        case 6:
            if(!isempty(start))
            {
                elem=delbtwa(start,&end);
                if(elem != -999)
                    printf("Deleted element : %d\n",elem);
                printf("The list is now \n");
                traverseforward(start);
                traversereverse(end);
            }
            else
                printf("The list is empty\n");

            break;
        case 7:
            if(!isempty(start))
            {
                elem=delbtwb(&start);
                if(elem != -999)
                    printf("Deleted element : %d\n",elem);
                printf("The list is now \n");
                traverseforward(start);
                traversereverse(end);
            }
            else
                printf("The list is empty\n");

            break;
        case 8:
            if(!isempty(start))
            {
                elem=delend(&start,&end);
                printf("Deleted element : %d\n",elem);
                printf("The list is now \n");
                traverseforward(start);
                traversereverse(end);
            }
            else
                printf("The list is empty\n");

            break;
        case 0:
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }
}
