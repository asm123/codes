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
	int t = read ();
	while (t--)
	{
		int n = read (), c = read (), stall[n], i;
		for (i = 0; i < n; i++)
		  stall[i] = read ();
		qsort (stall, n, sizeof (int), compare);
		int low = 0, high = stall[n-1] - stall[0], dist = 0;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			int p = 1, prev = stall[0];
			for (i = 1; i < n; i++)
			{
				if (stall[i] - prev >= mid)
				{
					prev = stall[i];
					p++;
				}
			}
			if (p < c)
			  high = mid - 1;
			else
			{
				low = mid + 1;
				if (mid > dist)
				  dist = mid;
			}
		}
		printf ("%d\n", dist);
	}
	return 0;
}
