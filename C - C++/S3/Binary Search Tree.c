#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int num;
    struct tree * lchild,* rchild;
};

void inorder(struct tree * root)
{
    if(root==NULL)
        return;
    inorder(root->lchild);
    printf("%5d",root->num);
    inorder(root->rchild);
}

void preorder(struct tree * root)
{
    if(root==NULL)
        return;
    printf("%5d",root->num);
    preorder(root->lchild);
    preorder(root->rchild);
}

void postorder(struct tree * root)
{
    if(root==NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%5d",root->num);
}

void insert(struct tree ** root)
{
    int n;
    struct tree * par ,* child,*temp;
    child=(struct tree *)malloc(sizeof(struct tree));
    printf("Enter number\n");
    scanf("%d",&n);
    child->num=n;
    child->lchild=NULL;
    child->rchild=NULL;
    if(*root == NULL)
        *root = child;
    else
    {
        temp=*root;
        while(temp!=NULL)
        {
            par=temp;
            if(n==temp->num)
            {
                printf("Same element is present\n");
                break;
            }
            else if(n>temp->num)
                temp=temp->rchild;
            else
               temp=temp->lchild;
        }
        if(par->num < n&&temp==NULL)
            par->rchild=child;
        else if(par->num > n&&temp==NULL)
            par->lchild=child;
    }
}

void search(struct tree * temp)
{
    int n;

    if(temp == NULL)
        printf("The tree is empty\n");
    else
    {
        printf("Enter number to search\n");
        scanf("%d",&n);
        while(temp!=NULL)
        {
            if(n==temp->num)
            {
                printf("Element is present\n");
                break;
            }
            else if(n>temp->num)
                temp=temp->rchild;
            else
               temp=temp->lchild;
        }
        if(temp==NULL)
            printf("Element is not present\n");
    }
}

void deltree(struct tree ** root)
{
    struct tree * par=NULL,*temp,*succ,*parsucc;
    int n,pos=0;
    if(*root==NULL)
    {
        printf("The tree is empty\n");
        return;
    }
    printf("\nEnter number\n");
    scanf("%d",&n);
    if((*root)->lchild==NULL&&(*root)->lchild==NULL&&(*root)->num==n)
        *root=NULL;
    else
    {
        temp=*root;
        while(temp!=NULL)
        {
            if(n==temp->num)
                break;
            else if(n>temp->num)
            {
                par=temp;
                temp=temp->rchild;
                pos=1;
            }
            else
            {
                par=temp;
                temp=temp->lchild;
                pos=2;
            }

        }
        if(temp==NULL)
            printf("No such number\n");
        else if(temp->lchild==NULL&&temp->rchild==NULL)
        {
            if(pos==1)
                par->rchild=NULL;
            else
                par->lchild=NULL;
        }
        else if(temp->lchild!=NULL&&temp->rchild!=NULL)
        {
            int t=0;
            succ=temp->rchild;
            parsucc=temp;
            while(succ->lchild!=NULL)
            {
                t=1;
                parsucc=succ;
                succ=succ->lchild;
            }
            if(pos==1)
            {
                par->rchild=succ;
                (par->rchild)->lchild=temp->lchild;
                if(t==1)
                {
                    (par->rchild)->rchild=temp->rchild;
                    parsucc->lchild=NULL;
                }

            }

            else
            {
                par->lchild=succ;
                (par->lchild)->lchild=temp->lchild;

                if(t==1)
                {
                    (par->lchild)->rchild=temp->rchild;
                    parsucc->lchild=NULL;
                }

            }

        }
        else
        {
            if(temp->lchild!=NULL)
            {
                if(pos==1)
                    par->rchild=temp->lchild;
                else
                    par->lchild=temp->lchild;
            }
            else
            {
                if(pos==1)
                    par->rchild=temp->rchild;
                else
                    par->lchild=temp->rchild;
            }

        }

    }
}

void main()
{
    struct tree * root = NULL;
    int op=1;
    while(op!=0)
    {
        printf("\nSelect option\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("0. Exit\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            insert(&root);
            printf("\nInorder Traversal\n");
            inorder(root);
	    printf("\nPreorder Traversal\n");
            preorder(root);
	    printf("\nPostorder Traversal\n");
	    postorder(root);
            break;
        case 2:
            deltree(&root);
            printf("\nInorder Traversal\n");
            inorder(root);
	    printf("\nPreorder Traversal\n");
            preorder(root);
	    printf("\nPostorder Traversal\n");
	    postorder(root);
            break;
        case 3:
            search(root);
            break;
        case 0:
            break;
        default:
            printf("Invalid Option\n");
            break;
        }

    }
}
