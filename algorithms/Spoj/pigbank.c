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
		int e = read (), f = read (), n, wt[10001], i, j, T, p, w;
		T = f - e;
		wt[0] = 0;
		for (i = 1; i <= T; i++)
		  wt[i] = 1000000000;
		n = read ();
		for (i = 0; i < n; i++)
		{
			p = read ();
			w = read ();
			for (j = 0; j+w <= T; j++)
			{
				if (wt[j] != 1000000000 && wt[j+w] > wt[j] + p)
				  wt[j+w] = wt[j] + p;
			}
		}
		if (wt[T] == 1000000000)
		  printf ("This is impossible.\n");
		else
		  printf ("The minimum amount of money in the piggy-bank is %d.\n", wt[T]);
	}
	return 0;
}