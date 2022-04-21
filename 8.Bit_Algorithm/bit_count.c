#include <stdio.h>
int bit_count( int bitmap )
{
	int count=0;
	int i;
	for( i=0; i<32; i++ )
		if( bitmap & (1<<i) )
			count++;
	return count;
}

int main()
{
	int bitmap = 0x12345678;

	int count;

	count = bit_count(bitmap);
	printf("count=%d\n", count );
	return 0;
}
