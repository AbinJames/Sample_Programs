#include<stdio.h>

void main()
{
    float f,c;
    printf("Enter the temperture in Fahrenheit\n");
    scanf("%f",&f);
    c=(f-32.0)/1.8;
    printf("The temperature in Celsius is %2.2f",c);
}
