#include <stdio.h>

int gcd (int a, int b)
{
	if (b == 0)
	  return a;
	return gcd (b, a % b);
}

int mod (char b[], int a)
{
	int n = 0;
	for (int i = 0; b[i]; i++)
	{
		n = n * 10 + b[i] - 48;
		n = n % a;
	}
	return n;
}

int main (void)
{
	int t;
	scanf ("%d", &t);
	while (t--)
	{
		int a;
		char b[251];
		scanf ("%d %s", &a, b);
		if (a == 0)
		  printf ("%s\n", b);
		else
		  printf ("%d\n", gcd (a, mod (b, a)));
	}
	return 0;
}