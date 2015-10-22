#include <stdio.h>
#include <math.h>

inline int read ()
{
	char c;
	int n = 0;

	while ((c = getchar_unlocked ()) < 48);
	n += (c - '0');
	
	while ((c = getchar_unlocked ()) >= 48)
	  n = n * 10 + (c - '0');
	
	return n;
}

int main (void)
{
	int t = read ();
	while (t--)
	{
		int n = read (), i, s;
		long long int sum = 0, k;
		s = sqrt (n);
		for (i = 1; i <= s; i++)
		{
			if (n % i == 0)
			{
				sum += i;
				k = n / i;
				if (k != i)
				  sum += k;
			}
		}
		printf ("%lld\n", sum - n);
	}
	return 0;
}