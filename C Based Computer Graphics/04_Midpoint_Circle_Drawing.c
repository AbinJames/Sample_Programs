

#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

int main(void)
{


    float xc,yc,r,pk,xk,yk,k;
    printf("Midpoint Circle Drawing\n");
    printf("r = ");
    scanf("%f",&r);
    printf("xc = ");
    scanf("%f",&xc);
    printf("yc = ");
    scanf("%f",&yc);
    int gdriver = DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"");
    pk=(5/4)-r;
    xk=0;
    yk=r;

    putpixel(xc+xk,yc+yk,10);
    while(xk<yk)
    {
        if(pk<0)
                pk+=((2*(++xk))+1);
            else
                pk+=((2*(++xk))-(2*(--yk))+1);
            putpixel(xc+xk,yc+yk,10);
            putpixel(xc-xk,yc+yk,10);
            putpixel(xc+xk,yc-yk,10);
            putpixel(xc-xk,yc-yk,10);
            putpixel(xc+yk,yc+xk,10);
            putpixel(xc-yk,yc+xk,10);
            putpixel(xc+yk,yc-xk,10);
            putpixel(xc-yk,yc-xk,10);

            delay(50);

    }
    getch();
    closegraph();
    return 0;
}


