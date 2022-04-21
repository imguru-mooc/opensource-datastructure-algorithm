#include <stdio.h>
const int m1  = 0x55555555; 
const int m2  = 0x33333333; 
const int m4  = 0x0f0f0f0f; 
const int m8  = 0x00ff00ff; 
const int m16 = 0x0000ffff; 
const int h01 = 0x01010101; 

int popcount_a(int x)
{
	x = (x & m1 ) + ((x >>  1) & m1 ); 
	x = (x & m2 ) + ((x >>  2) & m2 ); 
	x = (x & m4 ) + ((x >>  4) & m4 ); 
	x = (x & m8 ) + ((x >>  8) & m8 ); 
	x = (x & m16) + ((x >> 16) & m16); 
	return x;
}


int main()
{
	int bitmap = 0x12345678;
	int count;

	count = popcount_a(bitmap);
	printf("count=%d\n", count );
	return 0;
}
