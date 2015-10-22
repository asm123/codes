#include <stdio.h>

int main (void)
{
	int bee[1000001], i;
	bee[0] = 1;
	for (i = 1; i <= 1000000; i++)
	  bee[i] = bee[i-1] + 6 * i;
	while (1)
	{
		int n;
		scanf ("%d", &n);
		if (n == -1)
		  break;
		i = 0;
		while (bee[i] < n)
		  i++;
		if (bee[i] == n)
		  printf ("Y\n");
		else
		  printf ("N\n");
	}
	return 0;
}