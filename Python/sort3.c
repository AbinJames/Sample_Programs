#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void set(unsigned int* vector, int number);
void display(unsigned int* vector);
int size= 10000000/8;
int main(void)
{
	static const char n1[] = "input.list";
	static const char n2[] = "output.list";
	FILE *f1 = fopen(n1, "r");
	FILE *f2 = fopen(n2, "w");
	int line;
	int n = 0;
	int max_n = 100000000;
	int *V = malloc(size);
	if (f1 == 0)
		printf("Failed to open file %s for reading\n", n1);
	if (f2 == 0)
		printf("Failed to open file %s for writing\n", n2);
	while (fscanf(f1,"%d\n",&line)!=EOF)
		set(V, line);
	display(V);
	free(V);
	fclose(f1);
	fclose(f2);
	return(0);
}


void set(unsigned int * vector, int number)
{
	int byte;
	int bit;
	assert (number<size*8);
	byte=(size-1)-(number%8);
	bit = 7-number%8;
	vector[byte]=vector[byte]|1<<bit;
}
void display(unsigned int * vector)
{
	unsigned int mask;
	int i,j;
	int num=0;
	for(i=size-1;i>=0;i--)
	{
		for(j=7;j>=0;j--)
		{
			mask=1<<j;
			if(vector[i]&mask)
				printf("%d\n",num);
			num++;
		}
	}
}
