
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main(void)
{


    float x1,y1,x2,y2,x,y,k,i;
    printf("Point Clipping\n");
    printf("Enter coordinates of rectangle\n");

    printf("Enter top left point\n");
    printf("x1 = ");
    scanf("%f",&x1);
    printf("y1 = ");
    scanf("%f",&y1);

    printf("Enter bottom right point\n");
    printf("x2 = ");
    scanf("%f",&x2);
    printf("y2 = ");
    scanf("%f",&y2);

    int gdriver = DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"");
    rectangle(x1,y1,x2,y2);
    printf("Enter number of points\n");
    printf("k = ");
    scanf("%f",&k);

    for(i=0;i<k;i++)
    {
        printf("x = ");
        scanf("%f",&x);
        printf("y = ");
        scanf("%f",&y);
        if((x>=x1&&x<=x2)&&(y>=y1&&y<=y2))
            putpixel(x,y,10);
    }
    delay(500);
    closegraph();
    return 0;
}
