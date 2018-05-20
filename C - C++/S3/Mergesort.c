#include<stdio.h>
void print(int a[],int l,int r)
{
    int i;
    for(i=l;i<=r;i++)
        printf("%5d",a[i]);
    printf("\n");
}

void mergesort(int a[],int l,int r)
{
    int mid;
    if(l<r)
    {
        mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

void merge(int a[],int l,int mid,int r)
{
	int i,j,k,c[10];
	for(k=l,i=l,j=mid+1;i<=mid&&j<=r;k++)
	{
		if(a[i]<a[j])
		{
			c[k]=a[i];
			i++;
		}
		else
		{
			c[k]=a[j];
			j++;
		}
	}
	while(i<=mid)
	{
		  c[k]=a[i];
		  i++;
		  k++;
	}
	while(j<=r)
	{
		c[k]=a[j];
		j++;
		k++;
	}
	for(i=l;i<k;i++)
		a[i]=c[i];
    printf("For left = %d, mid = %d, right = %d\n",l,mid,r);
	print(a,l,r);
}

void main()
{
    int a[10]={5,7,6,4,10,9,1,2,3,8},l=0,r=9;
    printf("The array is\n");
    print(a,l,r);
    mergesort(a,l,r);
    printf("The sorted array is\n");
    print(a,l,r);
}
