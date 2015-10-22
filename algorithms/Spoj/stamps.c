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
	return (*(int *)b - *(int *)a);
}

int main (void)
{
	int t = read (), k;
	for (k = 1; k <= t; k++)
	{
		int req = read (), n = read (), stamps[n], sum = 0, i;
		for (i = 0; i < n ; i++)
		{
			stamps[i] = read ();
			sum += stamps[i];
		}
		printf ("Scenario #%d:\n", k);
		if (req > sum)
		  printf ("impossible\n");
		else
		{
			qsort (stamps, n, sizeof (int), compare);
			i = 0;
			while (req > 0)
			{
				req -= stamps[i];
				i++;
			}
			printf ("%d\n", i);
		}
		printf ("\n");
	}

	return 0;
}