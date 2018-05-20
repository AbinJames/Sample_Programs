
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

int main(void)
{

    float xc,yc,r,pk,xk,yk,k;

    printf("Bresenham's Circle Drawing\n");
    printf("r = ");
    scanf("%f",&r);
    printf("xc = ");
    scanf("%f",&xc);
    printf("yc = ");
    scanf("%f",&yc);

    int gdriver = DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"");
    pk=3-2*r;
    xk=0;
    yk=r;

    putpixel(xc+xk,yc+yk,10);
    while(xk<yk)
    {
       if(pk<0)
                pk+=((4*(++xk))+6);
            else
                pk+=((4*(++xk))-(4*(--yk))+10);
            putpixel(xc+xk,yc+yk,10);
            putpixel(xc-xk,yc+yk,10);
            putpixel(xc+xk,yc-yk,10);
            putpixel(xc-xk,yc-yk,10);
            putpixel(xc+yk,yc+xk,10);
            putpixel(xc-yk,yc+xk,10);
            putpixel(xc+yk,yc-xk,10);
            putpixel(xc-yk,yc-xk,10);

            delay(200);
    }
    getch();
    closegraph();
    return 0;
}

