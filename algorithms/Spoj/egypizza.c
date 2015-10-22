#include <stdio.h>

int main (void)
{
	int N, i, t = 0, h = 0, p = 0, count = 1;
	scanf ("%d", &N);
	if (N == 0)
	{
		printf ("1\n");
		return 0;
	}
	for (i = 0; i < N; i++)
	{
		int n, d;
		scanf ("%d/%d", &n, &d);
		if (n == 3)
		  t++;
		else if (d == 4)
		  p++;
		else
		  h++;
	}
	if (t >= p)
	  count += t + (h / 2) + (h % 2);
	else if (t < p)
	{
		count += t;
		p -= t;
		if (h % 2 == 0)
		{
			count += (h / 2);
			if (p % 4 == 0)
			  count += (p / 4);
			else
			  count += (p / 4 + 1);
		}
		else
		{
			count += (h / 2) + 1;
			if (p > 2)
			{
				p -= 2;
				if (p % 4 == 0)
				  count += (p / 4);
				else
				  count += (p / 4 + 1);
			}
		}
	}
	printf ("%d\n", count);
	return 0;
}