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
	while (1)
	{
		int budget = read (), n = read ();
		if (budget == 0 && n == 0)
		  break;
		int fee[n], fun[n], sum[n + 1][budget + 1], i, j;
		for (i = 0; i < n; i++)
		{
			fee[i] = read ();
			fun[i] = read ();
		}
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= budget; j++)
			{
				if (i == 0 || j == 0)
				  sum[i][j] = 0;
				else if (fee[i-1] <= j)
				{
					if (fun[i-1] + sum[i-1][j-fee[i-1]] > sum[i-1][j])
					  sum[i][j] = fun[i - 1] + sum[i - 1][j - fee[i-1]];
					else
					  sum[i][j] = sum[i-1][j];
				}
				else
				  sum[i][j] = sum[i - 1][j];
			}
		}
		j = sum[n][budget];
		for (i = budget; i; i--)
		  if (sum[n][i] < j)
		    break;
		printf ("%d %d\n", i + 1, sum[n][budget]);
	}
  
	return 0;
}