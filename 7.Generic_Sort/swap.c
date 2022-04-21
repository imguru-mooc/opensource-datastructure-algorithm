#if 1
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

int main()
{
	double ad=3., bd=4.;
	int a=3, b=4;

	generic_swap( &a, &b, sizeof(a) );
	generic_swap( &ad,&bd, sizeof(ad) );

	printf("main : ad=%lf, bd=%lf\n", ad, bd );
	printf("main : a=%d, b=%d\n", a, b );
	return 0;
}
#endif
#if 0
#include <stdio.h>

void swap( void *a , void *b, int size )
{
	char t;
	int i;
	char *p = (char*)a;
	char *q = (char*)b;

	for(i=0; i<size; i++)
	{
		t = p[i];
		p[i] = q[i];
		q[i] = t;
	}
}

int main()
{
	double ad=3., bd=4.;
	int a=3, b=4;

	swap( &a, &b, sizeof(a) );
	swap( &ad,&bd, sizeof(ad) );

	printf("main : ad=%lf, bd=%lf\n", ad, bd );
	printf("main : a=%d, b=%d\n", a, b );
	return 0;
}
#endif
#if 0
#include <stdio.h>

void swap( char *a , char *b, int size )
{
	char t;
	int i;

	for(i=0; i<size; i++)
	{
		t = a[i];
		a[i] = b[i];
		b[i] = t;
	}
}

int main()
{
	double ad=3., bd=4.;
	int a=3, b=4;

	swap( (char*)&a, (char*)&b, sizeof(a) );
	swap( (char*)&ad, (char*)&bd, sizeof(ad) );

	printf("main : ad=%lf, bd=%lf\n", ad, bd );
	printf("main : a=%d, b=%d\n", a, b );
	return 0;
}
#endif
#if 0
#include <stdio.h>

void swap_int( int *a , int *b )
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

void swap_double( double *a , double *b )
{
	double t;

	t = *a;
	*a = *b;
	*b = t;
}
int main()
{
	double ad=3., bd=4.;
	int a=3, b=4;

	swap_int( &a, &b );
	swap_double( &ad, &bd );

	printf("main : ad=%lf, bd=%lf\n", ad, bd );
	printf("main : a=%d, b=%d\n", a, b );
	return 0;
}
#endif
#if 0
#include <stdio.h>
#define  TYPE   int
void swap( TYPE *a , TYPE *b )
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	double ad=3., bd=4.;
	int a=3, b=4;

	swap( &ad, &bd );
	swap( &a, &b );

	printf("main : ad=%lf, bd=%lf\n", ad, bd );
	printf("main : a=%d, b=%d\n", a, b );
	return 0;
}
#endif
#if 0
#include <stdio.h>
void swap( int *a , int *b )
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int a=3, b=4;

	swap( &a, &b );

	printf("main : a=%d, b=%d\n", a, b );
	return 0;
}
#endif


#if 0
#include <stdio.h>
void swap( int a , int b )
{
	int t;

	t = a;
	a = b;
	b = t;
	printf("swap : a=%d, b=%d\n", a, b );
}

int main()
{
	int a=3, b=4;

	swap( a, b );

	printf("main : a=%d, b=%d\n", a, b );
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int a=3, b=4;

	int t;

	t = a;
	a = b;
	b = t;

	printf("a=%d, b=%d\n", a, b );
	return 0;
}
#endif
