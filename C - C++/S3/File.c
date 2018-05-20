#include<stdio.h>
void main()
{
    int n,num,i,j;
    char c;
    FILE *fp,*fo,*fe;
    do
    {
        j=0;
        fp=fopen("data.txt","w+");
        printf("Enter the number you wish to enter\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&num);
            fprintf(fp,"%d\n",num);
        }
        rewind(fp);
        fo=fopen("odd.txt","w+");
        fe=fopen("even.txt","w+");
        for(i=0;i<n;i++)
        {
            fscanf(fp,"%d",&num);
            if(num%2==0)
            {
                fprintf(fe,"%d\n",num);
                j++;
            }
            else
                fprintf(fo,"%d\n",num);
        }
        printf("Contents of even.txt is\n");
        rewind(fe);
        for(i=0;i<j;i++)
        {
            fscanf(fe,"%d",&num);
            printf("%d\t",num);
        }
        printf("\nContents of odd.txt is\n");
        rewind(fo);
        for(i=0;i<n-j;i++)
        {
            fscanf(fo,"%d",&num);
            printf("%d\t",num);
        }
        fclose(fp);
        fclose(fe);
        fclose(fo);
        printf("\nDo you wish to enter again ? (Y/N)\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c=='Y'||c=='y');
}
