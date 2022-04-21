#if 1
#include <stdio.h>

#define FOO(x)      \
	({             \
    	10;         \
    	20;         \
	})

int main()
{
	int ret;
	ret = FOO(10);
	printf("ret=%d\n", ret );
	return 0;
}
#endif
#if 0
#include <stdio.h>

int foo()
{
	10;
	return 20;
}

int main()
{
	int ret;
	ret = foo(10);
	printf("ret=%d\n", ret );
	return 0;
}
#endif

#if 0
#include <stdio.h>

#define FOO(x)      \
	do{             \
    	10;         \
    	20;         \
	} while(0)

int main()
{
	int ret;
	ret = FOO(10);
	return 0;
}
#endif

#if 0
#include <stdio.h>

#define __FOO(x)  \
	*(x) = 20;    \
	printf("data=%d\n", *(x) )

#define FOO(x)    \
	const typeof(*(x)) *__x = x;   \
	__FOO(__x);

int main()
{
	int data=10;
	FOO(&data);
	return 0;
}
#endif

#if 0
#include <stdio.h>

void foo(const int *data )
{
	++*data;
	printf("data=%d\n", *data );
}

int main()
{
	int data=10;
	foo(&data);
	return 0;
}
#endif
