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
	int n = read ();
	int result = 0;
	while (n--)
	{
		int x = read ();
		result = result ^ x;
	}
	printf ("%d\n", result);
	return 0;
}
