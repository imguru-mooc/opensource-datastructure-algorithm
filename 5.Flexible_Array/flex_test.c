#include <stdio.h>
#include "flex_array.h" 

int main()
{
	int n=10;
	int *p;
	struct flex_array *fa;

	fa = flex_array_alloc( 4,2000,0 );
	flex_array_put(fa, 1500, &n, 0  );
	p = (int*)flex_array_get(fa, 1500);
	printf("fa[1500] = %d\n", *p );
	flex_array_free( fa );
	return 0;
}
