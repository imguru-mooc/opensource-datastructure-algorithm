#if 1
#include <stdio.h>
#include <stdlib.h>
typedef unsigned int u32;

void u32_swap(void *a, void *b, int size)
{
	u32 t = *(u32 *)a;
	*(u32 *)a = *(u32 *)b;
	*(u32 *)b = t;
}

void generic_swap(void *a, void *b, int size)
{
	char t;

	do {
		t = *(char *)a;
		*(char *)a++ = *(char *)b;
		*(char *)b++ = t;
	} while (--size > 0);
}

void sort(void *base, size_t num, size_t size,
	  int (*cmp_func)(const void *, const void *),
	  void (*swap_func)(void *, void *, int size))
{
	/* pre-scale counters for performance */
	int i = (num/2 - 1) * size, n = num * size, c, r;

	if (!swap_func)
		swap_func = (size == 4 ? u32_swap : generic_swap);

	/* heapify */
	for ( ; i >= 0; i -= size) {
		for (r = i; r * 2 + size < n; r  = c) {
			c = r * 2 + size;
			if (c < n - size &&
					cmp_func(base + c, base + c + size) < 0)
				c += size;
			if (cmp_func(base + r, base + c) >= 0)
				break;
			swap_func(base + r, base + c, size);
		}
	}

	/* sort */
	for (i = n - size; i > 0; i -= size) {
		swap_func(base, base + i, size);
		for (r = 0; r * 2 + size < i; r = c) {
			c = r * 2 + size;
			if (c < i - size &&
					cmp_func(base + c, base + c + size) < 0)
				c += size;
			if (cmp_func(base + r, base + c) >= 0)
				break;
			swap_func(base + r, base + c, size);
		}
	}
}

//----------------------------------------------------------------------------

int int_cmp(const void* a,const void* b)
{
	return  (*(int*)a - *(int*)b);
}

int main()
{
	int a[] = { 400,300,500,200,600,100,700 };
	int i;

	sort( a, 7, sizeof(a[0]), int_cmp, 0 );
	for(i=0; i<7; i++ )
		printf("%4d", a[i] );
	printf("\n");
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

void generic_swap(void *a, void *b, int size)
{
	char t;

	do {
		t = *(char *)a;
		*(char *)a++ = *(char *)b;
		*(char *)b++ = t;
	} while (--size > 0);
}

void bubble( void *a, int n , int size, int (*cmp)(const void*,const void*))
{
	int i,j;
	for(i=0; i<n-1; i++ )
		for(j=0; j<n-1-i; j++ )
			if( cmp( (char*)a+j*size,(char*)a+(j+1)*size) )
				generic_swap( (char*)a+j*size, 
						(char*)a+(j+1)*size, 
						size);
}

//----------------------------------------------------------------------------

int int_cmp(const void* a,const void* b)
{
	return  (*(int*)a - *(int*)b) > 0;
}

int main()
{
	int a[] = { 400,300,500,200,600,100,700 };
	int i;

	qsort( a, 7, sizeof(a[0]), int_cmp );
	for(i=0; i<7; i++ )
		printf("%4d", a[i] );
	printf("\n");
	return 0;
}
#endif

#if 0
#include <stdio.h>

void generic_swap(void *a, void *b, int size)
{
	char t;

	do {
		t = *(char *)a;
		*(char *)a++ = *(char *)b;
		*(char *)b++ = t;
	} while (--size > 0);
}

void bubble( void *a, int n , int size)
{
	int i,j;
	for(i=0; i<n-1; i++ )
		for(j=0; j<n-1-i; j++ )
			if( *(int*)((char*)a+j*size) > *(int*)((char*)a+(j+1)*size) )
				generic_swap( (char*)a+j*size, 
						(char*)a+(j+1)*size, 
						size);
}

int main()
{
	int a[] = { 400,300,500,200,600,100,700 };
	int i;

	bubble( a, 7, sizeof(a[0]) );
	for(i=0; i<7; i++ )
		printf("%4d", a[i] );
	printf("\n");
	return 0;
}
#endif
#if 0
#include <stdio.h>

void generic_swap(void *a, void *b, int size)
{
	char t;

	do {
		t = *(char *)a;
		*(char *)a++ = *(char *)b;
		*(char *)b++ = t;
	} while (--size > 0);
}
void bubble( int *a, int n )
{
	int i,j;
	for(i=0; i<n-1; i++ )
		for(j=0; j<n-1-i; j++ )
			if( a[j] > a[j+1] )
				generic_swap( a+j, a+j+1, sizeof(a[0]));
}
int main()
{
	int a[] = { 4,3,5,2,6,1,7 };
	int i;

	bubble( a, 7 );
	for(i=0; i<7; i++ )
		printf("%4d", a[i] );
	printf("\n");
	return 0;
}
#endif
