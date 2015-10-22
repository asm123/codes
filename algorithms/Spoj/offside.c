#include <stdio.h>
#include <stdlib.h>

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

int compare (const void * a, const void * b)
{
	return ( *(int *)a - *(int *)b );
}

int main (void)
{
	while (1)
	{
		int a = read (), d = read ();
		if (a == 0 && d == 0)
		  break;
		int b[a], c[d], i;
		for (i = 0; i < a; i++)
		  b[i] = read ();
		for (i = 0; i < d; i++)
		  c[i] = read ();
		qsort (b, a, sizeof (int), compare);
		qsort (c, d, sizeof (int), compare);
		if (b[0] < c[1])
		  printf ("Y\n");
		else
		  printf ("N\n");
	}
	return 0;
}