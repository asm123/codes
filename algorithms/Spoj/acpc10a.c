#include <stdio.h>

int main (void)
{
	while (1)
	{
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0)
			break;
		if (c - b == b - a)
			printf ("AP %d\n", (c << 1) - b);
		else
			printf ("GP %d\n", (c * c) / b);
	}
	return 0;
}
