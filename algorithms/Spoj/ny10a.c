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
		int n = read (), i, count[8];
		for (i = 0; i < 8; i++)
		  count[i] = 0;
		char toss[50], l, pl;
		scanf ("%s", toss);
		pl = toss[0];
		l = toss[1];
		i = 2;
		while (toss[i])
		{
			if (pl == 'T' && l == 'T' && toss[i] == 'T')
			  count[0]++;
			else if (pl == 'T' && l == 'T' && toss[i] == 'H')
			  count[1]++;
			else if (pl == 'T' && l == 'H' && toss[i] == 'T')
			  count[2]++;
			else if (pl == 'T' && l == 'H' && toss[i] == 'H')
			  count[3]++;
			else if (pl == 'H' && l == 'T' && toss[i] == 'T')
			  count[4]++;
			else if (pl == 'H' && l == 'T' && toss[i] == 'H')
			  count[5]++;
			else if (pl == 'H' && l == 'H' && toss[i] == 'T')
			  count[6]++;
			else if (pl == 'H' && l == 'H' && toss[i] == 'H')
			  count[7]++;
			pl = l;
			l = toss[i];
			i++;
		}
		printf ("%d ", n);
		for (i = 0; i < 8; i++)
		  printf ("%d ", count[i]);
		printf ("\n");
	}
	return 0;
}