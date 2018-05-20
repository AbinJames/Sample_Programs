#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>



int main(void)
{
    int gdriver = DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"");
    int x=0,i,j;
    int speed = 20;
    //boat moving
    float y = 0;
    while(x<700)
    {
        delay(speed);
        cleardevice();

        //boat
        //ellipse(50+x,240-y,325,180,50,10);
        if(x>200)
        {
            y+=.5;
            line(10+x,245-y,90+x,240-y);
            line(20+x,230-y,90+x,225-y);

            line(90+x,240-y,95+x,232.5-y);
            line(90+x,225-y,95+x,232.5-y);

            line(20+x,230-y,5+x,210-y);
            line(5+x,210-y,10+x,245-y);


            line(35+x,237.5-y,55+x,236-y);
            line(55+x,237.5-y,57.5+x,246-y);
            line(35+x,237.5-y,35.5+x,242.5-y);
            line(35.5+x,242.5-y,57.5+x,246-y);


            if(y<75)
            {
                line(45+x,250-y,45+x,252.5-y);
                circle(50+x,257.5-y,5);
                circle(40+x,257.5-y,5);
                line(85+x,250-y,85+x,242.5-y);
                circle(85+x,252.5-y,5);
            }

        }
        else
        {
            line(10+x,245-y,90+x,245-y);
            line(20+x,230-y,90+x,230-y);

            line(90+x,245-y,95+x,237.5-y);
            line(90+x,230-y,95+x,237.5-y);

            line(20+x,230-y,10+x,210-y);
            line(10+x,210-y,10+x,245-y);
            line(35+x,240-y,55+x,240-y);
            line(55+x,240-y,55+x,250-y);
            line(35+x,240-y,35+x,245-y);
            line(35+x,245-y,55+x,250-y);
            line(45+x,250-y,45+x,252.5-y);
                circle(50+x,257.5-y,5);
                circle(40+x,257.5-y,5);
                line(85+x,255-y,85+x,247-y);
                circle(85+x,257-y,5);


        }





        line(0,261,700,261);
        x+=1;
        if(x%10==0)
            speed-=1;
        if(speed==0)
            speed = 1;

    }







    getch();
    closegraph();
    return 0;
}



