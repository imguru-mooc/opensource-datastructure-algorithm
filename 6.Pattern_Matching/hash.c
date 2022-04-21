#include <stdio.h>
#include <string.h>
int main()
{
	char x[] = "helol";
	int m = strlen(x);
	int hx=0;
	int i;
	for (hx = i = 0; i < m; ++i) 
	{
		hx = ((hx<<1) + x[i]);
		//hx = hx + x[i];
	}
	printf("hx=%d\n", hx );
	return 0;
}

