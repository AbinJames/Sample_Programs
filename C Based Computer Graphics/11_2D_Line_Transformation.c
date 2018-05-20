

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

float x1,y1,x2,y2,rr,sx,sy,tx,ty,a;

void scale()
{
    printf("Enter scaling factor\n");
    printf("Sx = ");
    scanf("%f",&sx);
    printf("Sy = ");
    scanf("%f",&sy);
    line(x1,y1,x1+sx*(x2-x1),y2+sy*(y2-y1));
}
void translate()
{
    printf("Enter translation factor\n");
    printf("Sx = ");
    scanf("%f",&tx);
    printf("Sy = ");
    scanf("%f",&ty);
    line(tx+x1,ty+y1,tx+x2,ty+y2);

}

void rotate()
{
    printf("Enter rotation angle\n");
    printf("a = ");
    scanf("%f",&a);
    rr = (3.14/180)*a;
    line( x1 ,
    	y1 ,
    	abs((x2*cos(rr))-(y2*sin(rr))) ,
    	abs((x2*sin(rr))+(y2*cos(rr))));
}

int main(void)
{
    int c = 0;
    int gdriver = DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"");
    while(c!=4)
    {
        printf("Enter option\n");
        printf("1. Scaling\n");
        printf("2. Rotation\n");
        printf("3. Translation\n");
        printf("4. Exit\n");
        scanf("%d",&c);
        cleardevice();
        printf("x1 = ");
        scanf("%f",&x1);
        printf("y1 = ");
        scanf("%f",&y1);
        printf("x2 = ");
        scanf("%f",&x2);
        printf("y2 = ");
        scanf("%f",&y2);
        setcolor(BLUE);
    line(x1,y1,x2,y2);
    setcolor(WHITE);
        switch(c)
        {
        case 1:
            scale();
            break;
        case 2:
            rotate();
            break;
        case 3:
            translate();
            break;
        }
    }
    getch();
    closegraph();
    return 0;
}

