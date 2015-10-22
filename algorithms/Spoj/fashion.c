#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
	return (*(int *)a - *(int *)b);
}

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
		int n = read (), i, sum = 0;
		int m[n], w[n];
		for (i = 0; i < n; i++)
		  m[i] = read ();
		for (i = 0; i < n; i++)
		  w[i] = read ();
		qsort (m, n, sizeof (int), compare);
		qsort (w, n, sizeof (int), compare);
		for (i = 0; i < n; i++)
		  sum += m[i] * w[i];
		printf ("%d\n", sum);
	}
	return 0;
}