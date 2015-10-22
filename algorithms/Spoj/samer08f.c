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
	int grid[101], i, n;
	grid[1] = 1;
	for (i = 2; i <= 100; i++)
	  grid[i] = grid[i-1] + i*i;
	while ((n = read ()))
	  printf ("%d\n", grid[n]);
	return 0;
}