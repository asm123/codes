#include <stdio.h>
#include <string.h>

int power (int a, int b)
{
	int d = 1;
	while (b--)
	  d *= a;
	return d;
}
int main (void)
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		char a[1010];
		long long int b;
		scanf ("%s %lld", a, &b);
		if (b == 0)
		  printf ("1\n");
		else
		{
			int d = a[strlen (a) - 1] - '0';
			if (b % 4 == 0)
			  printf ("%d\n", (power (d % 10, 4)) % 10);
			else
			  printf ("%d\n", (power (d % 10, b % 4)) % 10);
		}
	}
	return 0;
}
