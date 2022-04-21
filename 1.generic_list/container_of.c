#if 1
#include <stdio.h>

#define  container_of(ptr, type, member)      \
	(type*)((char*)ptr-(unsigned long)&((type*)0)->member)

typedef struct
{
	int a;
	int b;
	int c;
} AAA;

int main()
{
	AAA aaa={1,2,3};
	int *temp = &aaa.c;
	AAA *p;
	p = container_of( temp, AAA, c );
	printf("%d, %d, %d\n", p->a, p->b, p->c);
	return 0;
}
#endif
#if 0
#include <stdio.h>

typedef struct
{
	int a;
	int b;
	int c;
} AAA;

int main()
{
	AAA aaa={1,2,3};
	int *temp = &aaa.c;
	AAA *p;
	p = (AAA*)((char*)temp - (unsigned long)&((AAA*)0)->c);
	printf("%d, %d, %d\n", p->a, p->b, p->c);
	return 0;
}
#endif
