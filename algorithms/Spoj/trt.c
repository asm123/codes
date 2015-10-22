#include <stdio.h>

int v[2001], rev[2001][2001], n;

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

int max (int a, int b)
{
	if (a > b)
	  return a;
	return b;
}

int revenue (int i, int j, int day)
{
	if (rev[i][j])
	  return rev[i][j];
	if (i == j)
	  rev[i][j] = n * v[i];
	else
	  rev[i][j] = max (day * v[i] + revenue (i+1, j, day + 1), day * v[j] + revenue (i, j-1, day + 1));
	return rev[i][j];
}

int main (void)
{
	int i, j;
	for (i = 0; i < 2001; i++)
	  for (j = 0; j < 2001; j++)
	    rev[i][j] = 0;
	n = read ();
	for (i = 0; i < n; i++)
	  v[i] = read ();
	printf ("%d\n", revenue (0, n-1, 1));
	return 0;
}