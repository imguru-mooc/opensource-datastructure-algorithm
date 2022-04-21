#include <stdio.h>
#include <string.h>

#define OUTPUT(x)    printf("%d\n", x )
void BF(char *x, int m, char *y, int n) {
	int i, j;

	/* Searching */
	for (j = 0; j <= n - m; ++j) {
		for (i = 0; i < m && x[i] == y[i + j]; ++i);
		if (i >= m)
			OUTPUT(j);
	}
}

int main()
{
	char y[] = "how are you hello world hello";
	char x[] = "hello";

	BF( x, strlen(x), y, strlen(y) );
	return 0;
}
