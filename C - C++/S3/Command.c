#include<stdio.h>
void main(int argc,char *argv[])
{
    if(argc==2)
        printf("%s",strrev(argv[1]));
    else
        printf("Only one word input is allowed");
}
