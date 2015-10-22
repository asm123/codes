#include <stdio.h>
#include <math.h>

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
		int n = read ();
		int diag = ceil ((-1 + sqrt (8 * n + 1)) / 2);
		int term = n - (diag * (diag - 1)) / 2;
		if (term == 0)
		{
			if (diag % 2 == 0)
			  printf ("TERM %d IS %d/%d\n", n, diag, 1);
			else
			  printf ("TERM %d IS %d/%d\n", n, 1, diag);
		}
		else
		{
			if (diag % 2 == 0)
			  printf ("TERM %d IS %d/%d\n", n, term, diag - term + 1);
			else
			  printf ("TERM %d IS %d/%d\n", n, diag - term + 1, term);
		}
	}
	return 0;
}
