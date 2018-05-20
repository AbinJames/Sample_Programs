

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

float x1=0,y1=450,x2=650,y2=450,r=10,i,rr,x=0,y=450;
void plot(float x, float y,float xdis, float ydis,float r, int c)
{
    setcolor(WHITE);
    ellipse(250,250,0,360,xdis,ydis);
    setcolor(c);
    circle(x,y,r);
    setfillstyle(SOLID_FILL,c);
    fillellipse(x,y,r,r);
}

int main(void)
{

    int gdriver = DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"");

    setcolor(YELLOW);
    circle(250,250,50);
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(250,250,50,50);

    plot(250,250,0,0,50,YELLOW);
    plot(350,250,100,75,15,RED);
    
    plot(375,315,150,125,16,YELLOW);

    plot(400,365,200,175,16,BLUE);
    

    getch();
    closegraph();
    return 0;
}

