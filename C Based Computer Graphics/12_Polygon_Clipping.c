
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
float x1[100],y1[100],x2[100],y2[100],xmin,ymin,xmax,ymax;
int k,i;
void setregion(float *x1, float *y1,float *x2, float *y2,int * l,int * t,int * b,int * r,float m,int check)
{

    if(check==2)
    {
        *x1=*x1+*x2;
        *x2=*x1-*x2;
        *x1=*x1-*x2;

        *y1=*y1+*y2;
        *y2=*y1-*y2;
        *y1=*y1-*y2;
    }
    if(*x1>=xmin)
        *l=0;
    if(*x1<=xmax)
        *r=0;
    if(*y1>=ymin)
        *t=0;
    if(*y1<=ymax)
        *b=0;
    if(*t==1)
    {
        *y1=ymin;
        *x1 = ((*y1-*y2)/m)+*x2;
        *t=0;
    }

    if(*b==1)
    {
        *y1=ymax;
        *x1 = ((*y1-*y2)/m)+*x2;
        *b=0;
    }

    if(*l==1)
    {
        *x1=xmin;
        *y1 = (m*(*x1-*x2))+*y2;
        *l=0;

    }

    if(*r==1)
    {
        *x1=xmax;
        *y1 = (m*(*x1-*x2))+*y2;
        *r=0;
    }

}
int main(void)
{


    int l1,b1,r1,t1,l2,b2,r2,t2;
    printf("Polygon Clipping\n");
    printf("Enter coordinates of rectangle\n");

    printf("Enter top left point\n");
    printf("xmin = ");
    scanf("%f",&xmin);
    printf("ymin = ");
    scanf("%f",&ymin);

    printf("Enter bottom right point\n");
    printf("xmax = ");
    scanf("%f",&xmax);
    printf("ymax = ");
    scanf("%f",&ymax);

    int gdriver = DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"");
    rectangle(xmin,ymin,xmax,ymax);
    printf("Enter number of lines\n");
    printf("k = ");
    scanf("%d",&k);
    setcolor(BLUE);
    for(i=0; i<k; i++)
    {
        printf("x1 = ");
        scanf("%f",&x1[i]);
        printf("y1 = ");
        scanf("%f",&y1[i]);
        printf("x2 = ");
        scanf("%f",&x2[i]);
        printf("y2 = ");
        scanf("%f",&y2[i]);
        line(x1[i],y1[i],x2[i],y2[i]);
    }
    setcolor(WHITE);
    for(i=0; i<k; i++)
    {
        t1=b1=l1=r1=t2=b2=l2=r2=1;

        while(l1==1||l2==1||t1==1||t2==1||b1==1||b2==1||r1==1||r2==1)
        {
            setregion(&x1[i],&y1[i],&x2[i],&y2[i],&l1,&t1,&b1,&r1,(y2[i]-y1[i])/(x2[i]-x1[i]),1);
            setregion(&x1[i],&y1[i],&x2[i],&y2[i],&l2,&t2,&b2,&r2,(y2[i]-y1[i])/(x2[i]-x1[i]),2);
        }

        line(x1[i],y1[i],x2[i],y2[i]);


    }
    delay(1500);
    closegraph();
    return 0;
}

