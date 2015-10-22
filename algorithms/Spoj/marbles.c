#include <stdio.h>

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
		long long int n = read (), k = read ();
		long long int r, i, ncr;
		n = n - 1;
		r = k - 1;
		if (r > n/2)
		  r = n - r;
		ncr = 1;
		for (i = 0; i < r; i++)
		{
			ncr *= (n - i);
			ncr /= (i + 1);
		}
		printf ("%lld\n", ncr);
	}
	return 0;
}