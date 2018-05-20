#include <stdio.h>
#include <stdlib.h>
//using malloc and setting memory as needed
static int intcmp(const void *p1, const void *p2);

int main(void)
{
    static const char n1[] = "input.list";
    static const char n2[] = "output.list";
    FILE *f1 = fopen(n1, "r");
    FILE *f2 = fopen(n2, "w");
    
    int line;
    int n = 0;
    int max_n = 0;
	int *V = malloc(sizeof(int)*max_n);

    if (f1 == 0)
        printf("Failed to open file %s for reading\n", n1);
    if (f2 == 0)
        printf("Failed to open file %s for writing\n", n2);

	while (fscanf(f1,"%d\n",&line)!=EOF)
	{
		 
        if (n == max_n)
        {
            int new_n = (max_n + 2) * 2;
            int *new_V = realloc(V, new_n * sizeof(*V));
            V = new_V;
            max_n = new_n;
        }
        V[n++] = line;
	}
    
    qsort(V, n, sizeof(V[0]), intcmp);

    for (int i = 0; i < n; i++)
        fprintf(f2, "%d\n", V[i]);

    free(V);
    fclose(f1);
    fclose(f2);
    return(0);
}

static int intcmp(const void *p1, const void *p2)
{
    int i1 = *(int *)p1;
    int i2 = *(int *)p2;
    if (i1 < i2)
        return -1;
    else if (i1 > i2)
        return +1;
    else
        return 0;
}
