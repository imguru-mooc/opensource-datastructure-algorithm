#include <stdio.h>
#include <stdlib.h>
struct flex
{
	int info;
	int count;
	int a[];
};

int main()
{
	int count=100;
	struct flex *fa;
	fa = malloc(sizeof(struct flex)+sizeof(int)*count );
	fa->count = count;
	fa->a[0] = 1;
	fa->a[99] = 100;
	return 0;
}
