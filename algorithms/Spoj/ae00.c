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
	int n = read (), i, j, count = 0;
	for (i = 1; i <= n; i++)
	  for (j = 1; j*j <= i; j++)
	    if (i % j == 0)
	      count++;
	printf ("%d\n", count);
	
	return 0;
}
