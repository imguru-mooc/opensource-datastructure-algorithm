#if 1
#include <stdio.h>

#define BITS_PER_LONG 64
unsigned long __ffs(unsigned long word)
{
	int num = 0;

#if BITS_PER_LONG == 64
	if ((word & 0xffffffff) == 0) {
		num += 32;
		word >>= 32;
	}
#endif
	if ((word & 0xffff) == 0) {
		num += 16;
		word >>= 16;
	}
	if ((word & 0xff) == 0) {
		num += 8;
		word >>= 8;
	}
	if ((word & 0xf) == 0) {
		num += 4;
		word >>= 4;
	}
	if ((word & 0x3) == 0) {
		num += 2;
		word >>= 2;
	}
	if ((word & 0x1) == 0)
		num += 1;
	return num;
}

int main()
{
	unsigned long bitmap = 0x80000000UL;
	if( bitmap != 0 )
		printf("%lu\n", __ffs(bitmap));
	else
		printf("세팅된 비트가 없습니다.\n");
	return 0;
}
#endif

#if 0
#include <stdio.h>

int __ffs(int word)
{
	int num = 0;

	if ((word & 0xffff) == 0) {
		num += 16;
		word >>= 16;
	}
	if ((word & 0xff) == 0) {
		num += 8;
		word >>= 8;
	}
	if ((word & 0xf) == 0) {
		num += 4;
		word >>= 4;
	}
	if ((word & 0x3) == 0) {
		num += 2;
		word >>= 2;
	}
	if ((word & 0x1) == 0)
		num += 1;
	return num;
}

int main()
{
	          // 00000000 00000000 00000000 00000000
	int bitmap = 0x80000000;
	if( bitmap != 0 )
		printf("%d\n", __ffs(bitmap));
	else
		printf("세팅된 비트가 없습니다.\n");
	return 0;
}
#endif

#if 0
#include <stdio.h>
int my_ffs( int bitmap )
{
	int i;
	for( i=0; i<32; i++ )
		if( bitmap & (1<<i) )
			break;
	return i;
}

int main()
{
	          // 00000001 00000000 00000000 00000000
	int bitmap = 0x01000000;
	printf("%d\n", my_ffs(bitmap));
	return 0;
}
#endif
