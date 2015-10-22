#include <stdio.h>

inline long long int read ()
{
	char c;
	long long int n = 0;

	while ((c = getchar_unlocked ()) < 48);
	n += (c - '0');
	
	while ((c = getchar_unlocked ()) >= 48)
	  n = n * 10 + (c - '0');
	
	return n;
}

int main (void)
{
	int t = read (), i = 1;
	while (i <= t)
	{
		long long int r = read ();
		printf ("Case %d: %.2lf\n", i++, (double)4 * r * r + 0.25);
	}
	return 0;
}