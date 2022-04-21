#include <stdio.h>
#include <string.h>

#define OUTPUT(x)    printf("%d\n", x )

void preMp(char *x, int m, int mpNext[]) {
	int i, j;

	i = 0;
	j = mpNext[0] = -1;
	while (i < m) {
		while (j > -1 && x[i] != x[j])
			j = mpNext[j];
		mpNext[++i] = ++j;
	}
}

void MP(char *x, int m, char *y, int n) {
	int i, j, mpNext[256];

	/* Preprocessing */
	preMp(x, m, mpNext);

	/* Searching */
	i = j = 0;
	while (j < n) {
		while (i > -1 && x[i] != y[j])
			i = mpNext[i];
		i++;
		j++;
		if (i >= m) {
			OUTPUT(j - i);
			i = mpNext[i];
		}
	}
}

int main()
{
	//int mpNext[256];
	int i;
	char y[] = "how are you gagggagg world hello";
	char x[] = "gagggagg";

	/*
	preMp( x, strlen(x), mpNext );
	for(i=0; i<(strlen(x)+1); i++ )
		printf("%4d", mpNext[i] );
	printf("\n");
	*/
	MP( x, strlen(x), y, strlen(y));
	return 0;
}




