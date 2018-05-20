
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

int main(void)
{
    float x1,x2,y1,y2,dx,dy,pk,xk,yk;
    printf("Bresenham's Algoritm");
    printf("x1 = ");
    scanf("%f",&x1);
    printf("y1 = ");
    scanf("%f",&y1);
    printf("x2 = ");
    scanf("%f",&x2);
    printf("y2 = ");
    scanf("%f",&y2);
    int gdriver = DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"");
    if(x1>x2&&y1>y2)
    {
        x1=x1+x2;
        x2=x1-x2;
        x1=x1-x2;

        y1=y1+y2;
        y2=y1-y2;
        y1=y1-y2;
    }
    dx=abs(x2-x1);
    dy=abs(y2-y1);

    pk=(2*dy)-(2*dx);

    putpixel(x1,y1,10);
    xk=x1;
    yk=y1;
    while(xk!=x2)
    {
        if(pk<0)
        {
            putpixel(++xk,yk,10);
            pk+=2*dy;
        }
        else
        {
            putpixel(++xk,++yk,10);
            pk+=((2*dy)-(2*dx));
        }
        delay(500);

    }
    //line(100,100,400,400);
    getch();
    closegraph();
    return 0;
}


