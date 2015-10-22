#include <stdio.h>

int power (int a, int b)
{
	int p = 1;
	while (b--)
	  p *= a;
	return p;
}


int main (void)
{
	int a, t;
	long long int b;
	scanf ("%d", &t);
	while (t--)
	{
		scanf ("%d %lld", &a, &b);
		if (a == 0)
		  printf ("0\n");
		else if (b == 0)
		  printf ("1\n");
		else
		{
			if (b % 4 == 0)
			  printf ("%d\n", (power (a % 10, 4)) % 10);
			else
			  printf ("%d\n", (power (a % 10, b % 4)) % 10);
		}
	}
	return 0;
}
