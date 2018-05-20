#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void boat(float x1,float y1,float x2, float y2,float x3, float y3,float x4, float y4)
{
    line(x1,y1,x2,y2);
    line(x1,y1,x3,y3);
    line(x2,y2,x4,y4);
    if(y3<240)
        line(x3,y3,x4,y4);
}

int main(void)
{
    int gdriver = DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"");
    int x=0,i,j;
    //boat moving
    float x1 = 0, y1 = 220, x2= 75,y2 = 220, x3 = 10, y3 = 240 , x4 = 65, y4 = 240;

    while(x<700)
    {
        delay(20);
        cleardevice();

        //boat
        boat(x1+x,y1,x2+x,y2,x3+x,y3,x4+x,y4);

        //iceberg
        line(500,240,510,200);
        line(510,200,515,210);
        line(515,210,520,160);
        line(520,160,570,240);

        line(0,240,700,240);

        if(65+x==500)
        {
            x1+=x;x2+=x;x3+=x;x4+=x;
            break;
        }


        x+=5;
    }
    cleardevice();
    y2=y4=240;
    x3=445;
    x2=500;
    y3=210;
    x4 = 475;
    y1 = 195;
    x1 = 455;
    boat(x1,y1,x2,y2,x3,y3,x4,y4);
    float m1 = (y2-y1)/(x2-x1);
    float m2 = (y4-y3)/(x4-x3);
    float m3 = (y3 - y1)/(x3 - x1);
    float y = 0;
    while(y<240)
    {
        delay(20);
        cleardevice();

        //boat
        if(y3+y<240)
            boat(x1,y1+y,( (y2-y1-y)/m1 )+x1,y2, x3 ,y3+y, ( (y4-y3-y)/m2 )+x3 ,y4);
        else
            boat(x1,y1+y,( (y2-y1-y)/m1 )+x1,y2, ( (240-y1-y)/m3 )+x1 ,240, x4 ,y4);
        //iceberg
        line(500,240,510,200);
        line(510,200,515,210);
        line(515,210,520,160);
        line(520,160,570,240);

        line(0,240,700,240);

        if(y1+y==240)
            break;

        y+=.5;
    }

    //boat sinking






    getch();
    closegraph();
    return 0;
}


