#include <stdio.h>

int gcd (int a, int b)
{
	if (a == 0)
	  return b;
	while (b)
	{
		if (a > b)
		  a -= b;
		else
		  b -= a;
	}
	return a;
}

int main (void)
{
	int t;
	scanf ("%d", &t);
	while (t--)
	{
		int n;
		scanf ("%d", &n);
		int ingr[n];
		for (int i = 0; i < n; i++)
		  scanf ("%d", &ingr[i]);
		int g = ingr[0];
		for (int i = 1; i < n; i++)
		  g = gcd (g, ingr[i]);
		for (int i = 0; i < n; i++)
		  printf ("%d ", ingr[i] / g);
		printf ("\n");
	}
	return 0;
}