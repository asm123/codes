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
		int x = read (), y = read ();
		if (x == y)
		{
			if (x % 2 == 0)
			  printf ("%d\n", x + y);
			else
			  printf ("%d\n", x + y - 1);
		}
		else
		{
			if (x - y == 2)
			{
				if (x % 2 == 0)
				  printf ("%d\n", x + y);
				else
				  printf ("%d\n", x + y - 1);
			}
			else
			  printf ("No Number\n");
		}
	}
	return 0;
}