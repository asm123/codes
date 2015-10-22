#include <stdio.h>

inline unsigned long long int read ()
{
	char c;
	unsigned long long int n = 0;

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
		unsigned long long int a = read (), b = read (), c = read (), n, d;
		n = (c * 2) / (a + b);
		printf ("%llu\n", n);
		d = (b - a) / (n - 5);
		a = a - (2 * d);
		while (n)
		{
			printf ("%llu ", a);
			a += d;
			n--;
		}
		printf ("\n");
	}
	return 0;
}