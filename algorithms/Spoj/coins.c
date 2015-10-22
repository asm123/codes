#include <stdio.h>

long long int a[1000000];

long long int max (long long int a, long long int b)
{
	if (a > b)
	  return a;
	return b;
}

long long int getSum (long long int n)
{
	if (n == 0)
	  return 0;
	if (n <= 1000000)
	  return ( max (n, a[n/2] + a[n/3] + a[n/4]));
	return ( max (n, getSum (n / 2) + getSum (n / 3) + getSum (n / 4)));
}

int main (void)
{
	long long int n, i;

	a[0] = 0;
	for (i = 1; i <= 1000000; i++)
	{
		long long int sum = a[i / 2] + a[i / 3] + a[i / 4];
		a[i] = max (i, sum);
	}
	
	while (scanf("%lld", &n) != -1)
	{
		long long int sum = max (n, getSum (n / 2) + getSum (n / 3) + getSum (n / 4));
		printf ("%lld\n", sum);
	}
	
	return 0;
}

