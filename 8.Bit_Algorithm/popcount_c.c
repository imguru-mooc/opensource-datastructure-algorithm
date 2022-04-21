#include <stdio.h>
const int m1  = 0x55555555; 
const int m2  = 0x33333333; 
const int m4  = 0x0f0f0f0f; 
const int m8  = 0x00ff00ff; 
const int m16 = 0x0000ffff; 
const int h01 = 0x01010101; 

int popcount_c(int x)
{
	x -= (x >> 1) & m1;             
	x = (x & m2) + ((x >> 2) & m2); 
	x = (x + (x >> 4)) & m4;        
	return (x * h01) >> 24;  
}

int __sw_hweight32(int w)
{
	w -= (w >> 1) & 0x55555555;
	w =  (w & 0x33333333) + ((w >> 2) & 0x33333333);
	w =  (w + (w >> 4)) & 0x0f0f0f0f;
	return (w * 0x01010101) >> 24;
}

int main()
{
	int bitmap = 0x12345678;
	int count;

	count = __sw_hweight32(bitmap);
	printf("count=%d\n", count );
	return 0;
}
