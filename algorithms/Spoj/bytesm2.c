#include <stdio.h>

int max (int a, int b)
{
	if (a > b)
	  return a;
	return b;
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
		int h = read (), w = read (), i, j, stone[h+2][w+2], sum = 0;
		for (i = 0; i < h+2; i++)
		  for (j = 0; j < w+2; j++)
		    stone[i][j] = 0;
		for (i = 1; i <= h; i++)
		{
			for (j = 1; j <= w; j++)
			{
				stone[i][j] = read () + max (stone[i-1][j-1], max (stone[i-1][j], stone[i-1][j+1]));
				if (i == h)
				  sum = max (sum, stone[h][j]);
			}
		}
		printf ("%d\n", sum);
	}
	return 0;
}