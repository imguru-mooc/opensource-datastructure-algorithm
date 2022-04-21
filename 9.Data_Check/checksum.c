#include <stdio.h>
typedef unsigned short __sum16;

unsigned short from32to16(unsigned int x)
{
	/* add up 16-bit and 16-bit for 16+c bit */
	x = (x & 0xffff) + (x >> 16);
	/* add up carry.. */
	x = (x & 0xffff) + (x >> 16);
	return x;
}

unsigned int do_csum(const unsigned char *buff, int len)
{
	int odd;
	unsigned int result = 0;

	if (len <= 0)
		goto out;
	odd = 1 & (unsigned long) buff;
	if (odd) {
		result += (*buff << 8);
		len--;
		buff++;
	}
	if (len >= 2) {
		if (2 & (unsigned long) buff) {
			result += *(unsigned short *) buff;
			len -= 2;
			buff += 2;
		}
		if (len >= 4) {
			const unsigned char *end = buff + ((unsigned)len & ~3);
			unsigned int carry = 0;
			do {
				unsigned int w = *(unsigned int *) buff;
				buff += 4;
				result += carry;
				result += w;
				carry = (w > result);
			} while (buff < end);
			result += carry;
			result = (result & 0xffff) + (result >> 16);
		}
		if (len & 2) {
			result += *(unsigned short *) buff;
			buff += 2;
		}
	}
	if (len & 1)
		result += *buff;
	result = from32to16(result);
	if (odd)
		result = ((result >> 8) & 0xff) | ((result & 0xff) << 8);
out:
	return result;
}
__sum16 ip_fast_csum(const void *iph, unsigned int ihl)
{
	return (__sum16)~do_csum(iph, ihl*4);
}

int main()
{
	unsigned short ip[] = { 0x4510, 0x00c8, 0x244c, 0x4000, 0x4006, 
		0x0000, 0xc0a8, 0x3880, 0xc0a8, 0x3801 };

	unsigned short sum;
	sum = ip_fast_csum( ip, 5 );
	printf("%#x\n", sum );
	ip[5] = sum;
	//-----------------------------------------------------------------
	// ip[3] |= 3;
	ip[3]++;
	ip[4]--;
	sum = ip_fast_csum( ip, 5 );
	if( sum == 0 )
		printf("올바른 데이터 입니다.\n" );
	else
		printf("변형된 데이터 입니다.\n" );
	return 0;
}





