


#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

float x1=0,y1=450,x2=650,y2=450,r=10,i,rr,x=0,y=450;

int main(void)
{
    //rintf("Enter position of ball\n");
    //scanf("%f",&x);
    //scanf("%f",&y);
    int gdriver = DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"");
    int x=0,i,j;
    while(x<700)
    {
        delay(10);
        cleardevice();

        sector(100+x,100,0,180,45,45);
        line(100+x,100,100+x,150);
        line(75+x,150,75+x,200);
        circle(75+x,135,15);
        line(75+x,175,100+x,150);

        line(75+x,200,95+x,240);
        line(75+x,200,55+x,240);

        line(0,240,700,240);

        for(i=0; i<240; i+=20)
        {
             for(j=0; j<700; j+=20)
                if(j<=60+x||j>=145+x&&i>=95)
                   line(j,i,j,i+5);

            for(j=0; j<700; j+=20)
                if(i<=95)
                line(j,i+5,j,i);




        }

        x+=5;
        //delay(1);
    }





    getch();
    closegraph();
    return 0;
}

