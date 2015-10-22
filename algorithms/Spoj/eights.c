#include <stdio.h>

int main (void)
{
	int t;
	scanf ("%d", &t);
	while (t--)
	{
		unsigned long long n;
		scanf ("%llu", &n);
		printf ("%llu\n", 192 + 250 * (n - 1));
	}
	return 0;
}