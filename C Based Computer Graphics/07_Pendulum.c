
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

float x1=250,y1=250,x2=250,y2=350,r=10,i,rr,x,y;

void pendulum(float a)
{
    cleardevice();
    rr = (3.14/180)*a;
    x = x1 + cos(rr)*(x2-x1)+sin(rr)*(y2-y1);
    y = y1 + sin(rr)*(x2-x1)-cos(rr)*(y2-y1);
    line(x1,y1,x,y);
    circle(x,y,r);
    fillellipse(x,y,r,r);
    delay(50);
}


int main(void)
{
    float a=240;
    //a=angle, rr = radians
    int gdriver = DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"");
    while(!kbhit())
    {
        pendulum(a-=3);
        if(a<120)
            while(a<240)
                pendulum(a+=3);

    }
    getch();
    closegraph();
    return 0;
}
