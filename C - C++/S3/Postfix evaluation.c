#include<stdio.h>
#include<ctype.h>

void printstack(int a[],int top)
{
    int i;
    printf("The stack is\n");
    for(i=top;i>=0;i--)
        printf("%d\n",a[i]);
}
int push(int stack[],int item,int *top)
{
    (*top)++;
    stack[*top]=item;
}
int pop(int stack[],int *top)
{
    int n;
    n=stack[*top];
    (*top)--;
    return(n);
}
int cal(char op,int x,int y)
{
    switch(op)
    {
        case'+':
            return(y+x);
        case'-':
            return(y-x);
        case'*':
            return(y*x);
        case'/':
            return(y/x);
    }
}
void main()
{
    char str[10]="12+3*12/-";
    int result,i,stack[10],top=-1,x,y;
    for(i=0;str[i]!='\0';i++)
    {
        printf("\nCharacter : %c\n",str[i]);
        if(isdigit(str[i]))
        {
            push(stack,str[i]-48,&top);
            printstack(stack,top);
        }
        else
        {
            x=pop(stack,&top);
            y=pop(stack,&top);
            result=cal(str[i],x,y);
            push(stack,result,&top);
            printstack(stack,top);
        }
    }
    printf("\nthe result is %d",pop(stack,&top));
}





