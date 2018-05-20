

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>

int main(void)
{


    float x1,x2,y1,y2,dx,dy,step,xinc,yinc,count;
    printf("DDA Algoritm");
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

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    if(dx>dy)
        step=dx;
    else
        step=dy;
    xinc=dx/step;
    yinc=dy/step;

    putpixel(x1,y1,10);
    for(count=1;count<step;count++)
    {
        x1+=xinc;
        y1+=yinc;
        putpixel(x1,y1,10);
        delay(500);
    }
    //line(100,100,400,400);
    getch();
    closegraph();
    return 0;
}
