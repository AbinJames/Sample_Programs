
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main(void)
{
    int gdriver = DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"");

    //walls
    rectangle(50,150,250,350);
    rectangle(250,150,550,350);

    //roof
    line(50,150,150,75);
    line(150,75,250,150);
    line(450,75,150,75);
    line(450,75,550,150);

    //window
    rectangle(300,225,325,250);
    rectangle(325,225,350,250);
    rectangle(300,250,325,275);
    rectangle(325,250,350,275);

    //door
    rectangle(75,225,150,350);

    //door handle
    circle(80,290,5);

    getch();
    closegraph();
    return 0;
}
