#include <stdio.h>
unsigned int hweight(unsigned int w)
{
	unsigned int res = w - ((w >> 1) & 0x55);
	res = (res & 0x33) + ((res >> 2) & 0x33);
	return (res + (res >> 4)) & 0x0F;
}

int main()
{
	char data = 'a';

	if( hweight(data)%2 )
		data |= 0x80;

	data |= 0x2;
	data |= 0x4;
//---------------------------------

	if( hweight(data)%2 == 0 )
		printf("올바른 데이터 입니다.\n");
	else
		printf("변형된 데이터 입니다.\n");
	return 0;
}
