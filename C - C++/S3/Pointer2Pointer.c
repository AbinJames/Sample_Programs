#include<stdio.h>

void changeptrtoptra(int **app)
{
    printf("\nIn changeptrtoptra\n");
    printf("Valur of app = %u\n",app);
    printf("Address of app = %u\n",&app);
    printf("Content aat app = %d\n",*app);
    printf("Content aat aat app = %d\n",**app);
    **app= **app * 3;
}

void changeptra(int *ap)
{
    *ap= *ap * 2;
    printf("\nIn changeptra\n");
    printf("Value of ap = %u\n",ap);
    printf("Address of ap = %u\n",&ap);
    printf("Content at ap = %d\n",*ap);
    changeptrtoptra(&ap);
}

void main()
{
    int a = 5;
    printf("In main\n");
    printf("Value of a = %d\n",a);
    printf("Address of a = %u\n",&a);
    changeptra(&a);
    printf("Changed value of a = %d\n",a);
}
