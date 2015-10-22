#include <stdio.h>

int main (void)
{
	int t, n, i;
	scanf ("%d", &t);
	while (t--)
	{
		scanf ("%d", &n);
		long long int sum = 0;
		for (i = 0; i < n; i++)
		{
			long long int x;
			scanf ("%lld", &x);
			sum += x;
			if (sum >= n)
			  sum %= (long long int)n;
		}
		if (sum == 0)
		  printf ("YES\n");
		else
		  printf ("NO\n");
	}
	return 0;
}