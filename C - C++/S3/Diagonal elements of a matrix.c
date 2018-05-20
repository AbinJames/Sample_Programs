#include<stdio.h>
void main()
{
    int arr[20][20],i,j,r,c;
    char ch;
    do
    {
        system("cls");
        printf("Enter the number of rows\n");
        scanf("%d",&r);
        printf("Enter the number of columns\n");
        scanf("%d",&c);
        printf("Enter the elements of matrix\n");
        for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                {
                    scanf("%d",&arr[i][j]);
                }
            }
        printf("The diagonal elements of matrix are\n");
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(i==j)printf("%d\t",arr[i][j]);
            }

            printf("\n");
        }

        printf("\nDo you wish to enter again ? (Y/N)\n");
        fflush(stdin);
        scanf("%c",&ch);
    }
    while(ch=='Y'||ch=='y');
}
