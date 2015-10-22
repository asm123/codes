#include <stdio.h>

int main (void)
{
	int t;
	scanf ("%d", &t);
	while (t--)
	{
		long long int n;
		scanf ("%lld", &n);
		printf ("%lld\n", ((n * (n+2) * (2*n + 1))) / 8);
	}
	return 0;
}