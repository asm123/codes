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
	int t = read (), i, sum = 0;
	for (i = 0; i < t; i++)
	{
		int n;
		scanf ("%d", &n);
		if (n > 0)
		  sum += n;
	}
	printf ("%d\n", sum);
	return 0;
}