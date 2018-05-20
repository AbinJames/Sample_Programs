#include<stdio.h>

void print(char ch,char postfix[],char stack[],int top)
{
    printf("\nInfix   = %c\n",ch);
    printf("Postfix = %s\n",postfix);
    printf("top     = %d\n",top);
    printf("Stack   = %s\n",stack);
}

void push(char stack[],int * top, char ch)
{
    (*top)++;
    stack[*top]=ch;
}

int getpreced(char stack,char ch)
{
    if(stack =='^' && (ch=='*' || ch == '/' || ch == '+' || ch == '-'))
       return(0);
    if((stack=='*' || stack == '/')&&(ch == '+' || ch == '-'))
        return(0);
    if(stack==ch)
        return(0);
    return(1);

}

char pop(char stack[],int * top)
{
    return (stack[(*top)--]);
}
void main()
{
    char infix[15],postfix[15]="",stack[10]="",ch,temp;
    printf("Infix expression : ");
    scanf("%s",&infix);
    int top=-1,i,j;
    for(i=0;infix[i]!='\0';i++);
    infix[i++]=')';
    infix[i]='\0';
    ch='(';
    push(stack,&top,ch);
    print(ch,postfix,stack,top);
    for(i=0,j=0;infix[i]!='\0';i++)
    {
        ch = infix[i];
        if(ch=='(')
            push(stack,&top,ch);
        else if (ch=='*' || ch=='/' || ch=='-' || ch=='+' || ch == '^')
        {
            if(getpreced(stack[top],ch))
                push(stack,&top,ch);
            else
            {
                postfix[j++]=pop(stack,&top);
                push(stack,&top,ch);
            }
        }
        else if(ch==')')
        {
            while(stack[top]!='(')
                postfix[j++]=pop(stack,&top);
            temp = pop(stack,&top);
        }
        else
            postfix[j++]=ch;
        print(ch,postfix,stack,top);
    }
    postfix[j++]='\0';
    printf("Post fix expression : %s\n",postfix);
}
