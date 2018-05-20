#include<stdio.h>
#include<string.h>
void main()
{
    char name[100][100],temp[100];
    int i,n,j;
    printf("Enter number of students\n");
    scanf("%d",&n);
    printf("Enter names of students\n");
    fflush(stdin);
    for(i=0;i<n;i++)
    {
        printf("\n%d. ",i+1);
        gets(name[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
            {
                if(strcmpi(name[j],name[j+1])>0)
                    {
                        strcpy(temp,name[j]);
                        strcpy(name[j],name[j+1]);
                        strcpy(name[j+1],temp);
                    }
            }
    }
    system("cls");
    printf("\nThe listed students are\n");
    for(i=0;i<n;i++)
    {
        printf("\n%d. ",i+1);
        puts(name[i]);
    }

}
