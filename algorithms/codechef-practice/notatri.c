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
	int n;
	while ((n = read ()))
	{
		int stick[n], i, count = 0;
		for (i = 0; i < n; i++)
		  stick[i] = read ();
		qsort (stick, n, sizeof (int), compare);
		for (i = n - 1; i >= 2; i--)
		{
			int l = 0;
			int r = i - 1;
			while (l < r)
			{
				if (stick[l] + stick[r] < stick[i])
				{
					count += r - l;
					l++;
				}
				else
				  r--;
			}
		}
		printf ("%d\n", count);
	}
	return 0;
}