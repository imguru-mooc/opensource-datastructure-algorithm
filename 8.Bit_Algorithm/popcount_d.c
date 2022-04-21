#include <stdio.h>
const int m1  = 0x55555555; 
const int m2  = 0x33333333; 
const int m4  = 0x0f0f0f0f; 
const int m8  = 0x00ff00ff; 
const int m16 = 0x0000ffff; 
const int h01 = 0x01010101; 

int popcount_d(int x)
{
	int count;
	for (count=0; x; count++)
		x &= x - 1;
	return count;
}

int main()
{
	int bitmap = 0x10000000;
	int count;

	count = popcount_d(bitmap);
	printf("count=%d\n", count );
	return 0;
}
