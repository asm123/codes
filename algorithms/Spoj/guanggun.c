#include <stdio.h>

int main (void)
{
	long long int n;
	while (scanf ("%lld", &n) != EOF)
	  printf ("%lld\n", 81 * (n / 9) + (n % 9) * (n % 9));
	return 0;
}