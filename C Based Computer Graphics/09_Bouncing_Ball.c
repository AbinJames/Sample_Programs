

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

float x1=0,y1=450,x2=650,y2=450,r=10,i,rr,x=0,y=450;
void bounce(float x, float y)
{
    cleardevice();
    line(x1,y1,x2,y2);
    circle(x,y,r);
    fillellipse(x,y,r,r);
    delay(1);
}

int main(void)
{
    printf("Enter position of ball\n");
    scanf("%f",&x);
    scanf("%f",&y);
    int gdriver = DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"");
    int ydcr=y;
    while(x<x2)
    {
        while(y>ydcr)
            bounce(x+=.5,y--);
        ydcr+=20;
        if(ydcr<=450-r)
            while(y<450-r)
                bounce(x+=.5,y++);
        else
            while(x<x2)
                bounce(x+=.5,450-r);

    }
    closegraph();
    return 0;
}
